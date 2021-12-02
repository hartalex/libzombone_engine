#include "component.hpp"
#include <iostream>
#include <string>

Component::Component(int componentType, std::string componentName,
                     ObjectIdentifier objectIdentifier)
    : componentType(componentType), componentName(componentName),
      objectIdentifier(objectIdentifier), removed(0), setuped(0), isDirty(1) {
  time(&initialTime);
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()
            << " constructor was called with (" << componentType << ", "
            << componentName << ", " << objectIdentifier.objectType << ", "
            << objectIdentifier.objectName << ", " << objectIdentifier.objectId
            << ")" << std::endl;
}
Component::Component(int componentType, std::string componentName)
    : componentType(componentType), componentName(componentName), removed(0),
      setuped(0), isDirty(1) {
  objectIdentifier.objectId = -1;
  objectIdentifier.objectName = "Unknown";
  objectIdentifier.objectType = -1;
  time(&initialTime);
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " constructor was called with (" << componentType << ", "
            << componentName << ")";
}
Component::~Component() {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " destructor was called" << std::endl;
}
void Component::setup() {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " setup was called" << std::endl;
  setuped = 1;
}
void Component::tearDown() {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " tearDown was called" << std::endl;
}
void Component::input(Input i) {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " input was called with (" << i.getInput() << ")";
}
void Component::update() {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " update was called" << std::endl;
}
void Component::collide(ObjectIdentifier objectIdentifier) {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " collide was called with (" << objectIdentifier.objectType
            << ", " << objectIdentifier.objectName.c_str() << ", "
            << objectIdentifier.objectId << ")" << std::endl;
}
void Component::physics() {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " physics was called" << std::endl;
}
int Component::isRemoved() const {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " isRemoved was called returning " << removed << std::endl;
  return removed;
}
void Component::remove() {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " remove was called" << std::endl;
  removed = 1;
}
int Component::isSetup() const {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " isSetup was called returning " << setuped << std::endl;
  return setuped;
}
ObjectIdentifier Component::getObjectIdentifier() const {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " getObjectIdentifier was called" << std::endl;
  return objectIdentifier;
}

int Component::getType() const {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " getType was called returning " << componentType << std::endl;
  return componentType;
}

std::string Component::getName() const {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " getName was called returning " << componentName << std::endl;
  return componentName;
}

int Component::getObjectType() const {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " getObjectType was called return " << componentType
            << std::endl;
  return componentType;
}
std::string Component::getObjectName() const {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " getObjectName was called" << std::endl;
  return componentName;
}

double Component::getTicks() const {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " getTicks was called" << std::endl;
  time_t currentTime;
  time(&currentTime);
  return difftime(currentTime, initialTime);
}

int Component::getIsDirty() const {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " getIsDirty was called returning " << isDirty << std::endl;
  return isDirty;
}

void Component::setIsDirty(int i) {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " setIsDirty was called with (" << i << ")" << std::endl;
  isDirty = i;
}

void Component::render() {
  std::cout << "Mock Component " << objectIdentifier.objectId << " "
            << componentType << " " << componentName.c_str()

            << " render was called" << std::endl;
  setIsDirty(0);
}
