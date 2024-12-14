cmake_minimum_required(VERSION 3.28.3)
project(RuleParser)

set(parser_list
    Parser.cc
)

list(TRANSFORM parser_list PREPEND "src/parser/")

add_library(lib_parser STATIC ${parser_list})
target_include_directories(lib_parser PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cc)
target_link_libraries(${PROJECT_NAME} PUBLIC lib_parser)