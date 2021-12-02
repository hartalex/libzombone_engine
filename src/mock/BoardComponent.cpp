#include "BoardComponent.hpp"

#include <ncurses.h>
#include <stdlib.h>
#include <string>

#include "LoggerService.hpp"
#include "NameComponent.hpp"
#include "ObjectIdentifier.hpp"
#include "ScoreComponent.hpp"
#include "Transform2DComponent.hpp"
#include "types.hpp"

BoardComponent::BoardComponent(std::string name,
                               ObjectIdentifier objectIdentifier)
    : Component(TYPE_COMPONENT_BOARD, name, objectIdentifier) {}

void BoardComponent::setup() {}

BoardComponent::~BoardComponent() {}

void BoardComponent::changeViewSize(int height, int width) {
  (void)height;
  (void)width;
}

void BoardComponent::render() {}

void BoardComponent::addObject(ObjectIdentifier objectIdentifier) {
  (void)objectIdentifier;
}

int BoardComponent::moveObject(ObjectIdentifier objectIdentifier,
                               Transform2DComponent &direction) {
  (void)objectIdentifier;
  (void)direction;
  return 0;
}

void BoardComponent::removeObject(ObjectIdentifier objectIdentifier) {
  (void)objectIdentifier;
}
void BoardComponent::moveView(Transform2DComponent &direction) {
  (void)direction;
}
void BoardComponent::moveView(int x, int y) {
  (void)x;
  (void)y;
}

void BoardComponent::physics() {}
void BoardComponent::tearDown() {}

void BoardComponent::calcCollision(Transform2DComponent &transform) {
  (void)transform;
}

void BoardComponent::calcCollision(int x, int y) {
  (void)x;
  (void)y;
}

void BoardComponent::input(Input input) { (void)input; }
