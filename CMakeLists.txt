# FROM ME : there are 4 files necessary to compile (from the github in README)
# if deleted, download and reinstall


# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.7 FATAL_ERROR)

project(RuleParser)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# compiler must be 17
set(CMAKE_CXX_STANDARD 17)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

# using /MD flag for antlr4_runtime (for Visual C++ compilers only)
set(ANTLR4_WITH_STATIC_CRT OFF)

# Specify the version of the antlr4 library needed for this project.
# By default the latest version of antlr4 will be used.  You can specify a
# specific, stable version by setting a repository tag value or a link
# to a zip file containing the libary source.
# set(ANTLR4_TAG 4.13.2)
# set(ANTLR4_ZIP_REPOSITORY https://github.com/antlr/antlr4/archive/refs/tags/4.13.2.zip)

# add external build for antlrcpp
include(ExternalAntlr4Cpp)
# add antlr4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})

# set variable pointing to the antlr tool that supports C++
# this is not required if the jar file can be found under PATH environment
set(ANTLR_EXECUTABLE /usr/local/lib/java/antlr-4.13.0-complete.jar)
# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.
# FROM ME : given in the example of github, not necessary for current drawing project
#antlr_target(SceneGrammarParser grammar/Scene.g4 VISITOR
#             OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/generated/)

antlr_target(SceneGrammarParser grammar/Scene.g4 PARSER
             OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/generated/
             COMPILE_FLAGS -lib ${ANTLR_SampleGrammarLexer_OUTPUT_DIR})

# include generated files in project environment
include_directories(${PROJECT_SOURCE_DIR}/generated)


set(parser_list
    Parser.cc
)

list(TRANSFORM parser_list PREPEND "src/parser/")

set(antlr_list
    SceneLexer.cpp
    SceneParser.cpp
    SceneVisitor.cpp
    SceneBaseVisitor.cpp
    SceneListener.cpp
)

list(TRANSFORM antlr_list PREPEND "generated/")

add_library(lib_antlr STATIC ${antlr_list})


add_library(lib_parser STATIC ${parser_list})
target_include_directories(lib_parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_include_directories(lib_parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/generated)
target_link_libraries(lib_parser PUBLIC lib_antlr)
target_link_libraries(lib_parser PUBLIC antlr4_static)

# add generated grammar to demo binary target
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cc
               ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
               ${ANTLR_SampleGrammarParser_CXX_OUTPUTS})

target_link_libraries(${PROJECT_NAME} PUBLIC lib_parser)