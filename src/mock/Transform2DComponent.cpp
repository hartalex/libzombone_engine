#include "Transform2DComponent.hpp"

Transform2DComponent::~Transform2DComponent() {}

void Transform2DComponent::move(int vx, int vy) {
  (void)vx;
  (void)vy;
}

void Transform2DComponent::move(int vx, int vy, int hasMoved) {
  (void)vx;
  (void)vy;
  (void)hasMoved;
}

void Transform2DComponent::move(Transform2DComponent &transform) {
  (void)transform;
}

void Transform2DComponent::move(Transform2DComponent &transform, int hasMoved) {
  (void)transform;
  (void)hasMoved;
}

Transform2DComponent Transform2DComponent::unMove() { return *this; }

void Transform2DComponent::initializeXY(int xx, int yy) {
  (void)xx;
  (void)yy;
}
void Transform2DComponent::setXY(int xx, int yy) {
  (void)xx;
  (void)yy;
}
void Transform2DComponent::setXY(Transform2DComponent &transform) {
  (void)transform;
}
void Transform2DComponent::setX(int xx) { (void)xx; }
void Transform2DComponent::setY(int yy) { (void)yy; }

int Transform2DComponent::getX() const { return x; }
int Transform2DComponent::getY() const { return y; }

double Transform2DComponent::distance(Transform2DComponent &transform) const {
  (void)transform;
  return 0;
}

int Transform2DComponent::hasMovedThisFrame() const { return 0; }

void Transform2DComponent::render() {}

