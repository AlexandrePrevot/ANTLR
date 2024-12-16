#include <iostream>

#include "parser/Parser.h"

#include "antlr4-runtime/antlr4-runtime.h"
#include "antlr4-runtime/SceneLexer.h"
#include "antlr4-runtime/SceneParser.h"

bool Parser::parse() {
    std::cout << "I am parsing" << std::endl;

    return true;
}