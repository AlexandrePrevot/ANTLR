#include "visitors/ImageVisitor.h"

#include <vector>

#include "SceneBaseVisitor.h"

std::any ImageVisitor::visitFile(antlrcpptest::SceneParser::FileContext *ctx) {
  //std::vector<Element> elements;
//
  //for (auto element : ctx->elements) {
  //  elements.push_back(std::any_cast<Element>(visitAction(element)));
  //}
  std::any result; // = Scene() build the scene
  return result;
}

std::any ImageVisitor::visitAction(antlrcpptest::SceneParser::ActionContext *) {
  //Action action;

  //return Element(action);
  std::any result;
  return result;
}

std::any
ImageVisitor::visitShape(antlrcpptest::SceneParser::ShapeContext *ctx) {
  //return Element::convertShape(ctx->getText());
  std::any result;
  return result;
}