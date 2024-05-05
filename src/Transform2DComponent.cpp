#include "zombone_engine/Transform2DComponent.hpp"

#include <math.h>
#include <stdio.h>

namespace zombone_engine {

Transform2DComponent::~Transform2DComponent() {}

void Transform2DComponent::move(int vx, int vy) {
  setXY(getX() + vx, getY() + vy);
  hasMoved = 1;
}

void Transform2DComponent::move(int vx, int vy, int hasMoved) {
  setXY(getX() + vx, getY() + vy);
  this->hasMoved = hasMoved;
}

void Transform2DComponent::move(Transform2DComponent &transform) {
  move(transform.getX(), transform.getY());
}

void Transform2DComponent::move(Transform2DComponent &transform, int hasMoved) {
  move(transform.getX(), transform.getY(), hasMoved);
}

Transform2DComponent Transform2DComponent::unMove() {
  Transform2DComponent retval = Transform2DComponent(
      "direction", previous_x - getX(), previous_y - getY());
  return retval;
}

void Transform2DComponent::initializeXY(int xx, int yy) {
  setX(xx);
  previous_x = xx;
  setY(yy);
  previous_y = yy;
}
void Transform2DComponent::setXY(int xx, int yy) {
  setX(xx);
  setY(yy);
}
void Transform2DComponent::setXY(Transform2DComponent &transform) {
  setXY(transform.getX(), transform.getY());
}
void Transform2DComponent::setX(int xx) {
  previous_x = getX();
  x = xx;
}
void Transform2DComponent::setY(int yy) {
  previous_y = getY();
  y = yy;
}

int Transform2DComponent::getX() const { return x; }
int Transform2DComponent::getY() const { return y; }

double Transform2DComponent::distance(Transform2DComponent &transform) const {
  double square_difference_x =
      (transform.getX() - getX()) * (transform.getX() - getX());
  double square_difference_y =
      (transform.getY() - getY()) * (transform.getY() - getY());
  double sum = square_difference_x + square_difference_y;
  double value = sqrt(sum);
  return value;
}

int Transform2DComponent::hasMovedThisFrame() const { return hasMoved; }

void Transform2DComponent::render() {
  Component::render();
  // Reset has Moved
  hasMoved = 0;
}

}  // namespace zombone_engine
