#pragma once

#include <any>
#include <string>

#include "SceneBaseVisitor.h"
#include "antlr4-runtime.h"

class ImageVisitor : public antlrcpptest::SceneBaseVisitor {
public:
  std::any visitFile(antlrcpptest::SceneParser::FileContext *);
  std::any visitAction(antlrcpptest::SceneParser::ActionContext *);
  std::any visitShape(antlrcpptest::SceneParser::ShapeContext *);
};