#include <iostream>

#include "parser/Parser.h"

#include "antlr4-runtime.h"
#include "TLexer.h"
#include "TParser.h"

bool Parser::parse() {
    std::cout << "I am parsing" << std::endl;

    return true;
}