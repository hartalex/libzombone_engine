#include "zombone_engine/component.hpp"
using namespace std;

Component::Component(int componentType, string componentName,
                     ObjectIdentifier objectIdentifier)
    : componentType(componentType),
      componentName(componentName),
      objectIdentifier(objectIdentifier),
      removed(0),
      setuped(0),
      isDirty(1) {
  time(&initialTime);
}
Component::Component(int componentType, string componentName)
    : componentType(componentType),
      componentName(componentName),
      removed(0),
      setuped(0),
      isDirty(1) {
  time(&initialTime);
}
Component::~Component() {}
void Component::setup() { setuped = 1; }
void Component::tearDown() {}
void Component::input(Input) {}
void Component::update() {}
void Component::collide(ObjectIdentifier objectIdentifier) {
  (void)objectIdentifier;
}
void Component::physics() {}
int Component::isRemoved() const { return removed; }
void Component::remove() { removed = 1; }
int Component::isSetup() const { return setuped; }
int Component::getType() const { return componentType; }

string Component::getName() const { return componentName; }

int Component::getObjectType() const { return componentType; }

string Component::getObjectName() const { return componentName; }

double Component::getTicks() const {
  time_t currentTime;
  time(&currentTime);
  return difftime(currentTime, initialTime);
}

int Component::getIsDirty() const { return isDirty; }

void Component::setIsDirty(int i) { isDirty = i; }

void Component::render() { isDirty = 0; }

const ObjectIdentifier& Component::getObjectIdentifier() const {
  return objectIdentifier;
}
