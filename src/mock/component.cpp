#include "component.hpp"

#include <iostream>
#include <string>
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
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str() << " constructor was called with ("
       << componentType << ", " << componentName << ", "
       << objectIdentifier.getType() << ", " << objectIdentifier.getName()
       << ", " << objectIdentifier.getId() << ")" << endl;
}
Component::Component(int componentType, string componentName)
    : componentType(componentType),
      componentName(componentName),
      removed(0),
      setuped(0),
      isDirty(1) {
  time(&initialTime);
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " constructor was called with (" << componentType << ", "
       << componentName << ")";
}
Component::~Component() {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " destructor was called" << endl;
}
void Component::setup() {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " setup was called" << endl;
  setuped = 1;
}
void Component::tearDown() {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " tearDown was called" << endl;
}
void Component::input(Input i) {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " input was called with (" << i.getInput() << ")";
}
void Component::update() {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " update was called" << endl;
}
void Component::collide(ObjectIdentifier objectIdentifier) {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " collide was called with (" << objectIdentifier.getType() << ", "
       << objectIdentifier.getName().c_str() << ", " << objectIdentifier.getId()
       << ")" << endl;
}
void Component::physics() {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " physics was called" << endl;
}
int Component::isRemoved() const {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " isRemoved was called returning " << removed << endl;
  return removed;
}
void Component::remove() {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " remove was called" << endl;
  removed = 1;
}
int Component::isSetup() const {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " isSetup was called returning " << setuped << endl;
  return setuped;
}
const ObjectIdentifier& Component::getObjectIdentifier() const {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " getObjectIdentifier was called" << endl;
  return objectIdentifier;
}

int Component::getType() const {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " getType was called returning " << componentType << endl;
  return componentType;
}

string Component::getName() const {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " getName was called returning " << componentName << endl;
  return componentName;
}

int Component::getObjectType() const {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " getObjectType was called return " << componentType << endl;
  return componentType;
}
string Component::getObjectName() const {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " getObjectName was called" << endl;
  return componentName;
}

double Component::getTicks() const {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " getTicks was called" << endl;
  time_t currentTime;
  time(&currentTime);
  return difftime(currentTime, initialTime);
}

int Component::getIsDirty() const {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " getIsDirty was called returning " << isDirty << endl;
  return isDirty;
}

void Component::setIsDirty(int i) {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " setIsDirty was called with (" << i << ")" << endl;
  isDirty = i;
}

void Component::render() {
  cout << "Mock Component " << objectIdentifier.getId() << " " << componentType
       << " " << componentName.c_str()

       << " render was called" << endl;
  setIsDirty(0);
}

