#include "parser/Parser.h"

#include <iostream>
#include "antlr4-runtime.h"
#include "SceneLexer.h"
#include "SceneParser.h"
//#include "ImageVisitor.h"

using namespace std;
using namespace antlr4;


bool Parser::parse() {
    //std::cout << "I am parsing" << std::endl;

    std::ifstream stream;
    stream.open("input.scene");

    ANTLRInputStream input(stream);
    antlrcpptest::SceneLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    antlrcpptest::SceneParser parser(&tokens);    
    antlrcpptest::SceneParser::FileContext* tree = parser.file();
    //ImageVisitor visitor;
    //Scene scene = std::any_cast<Scene>(visitor.visitFile(tree));
    //scene.draw();

    return true;
}