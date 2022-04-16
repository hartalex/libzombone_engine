#include "ObjectFileFactory.hpp"

#include <iostream>
#include <string>

#include "ComponentFactory.hpp"
#include "ObjectData.hpp"
using namespace std;

vector<string> split(const string &str, char delim);

ObjectFileFactory::ObjectFileFactory(
    unique_ptr<ComponentFactory> componentFactory, string fileName)
    : componentFactory(move(componentFactory)) {
  cout << "Mock ObjectFileFactory constructor was called with ("
       << fileName.c_str() << ")" << endl;
}

ObjectFileFactory::~ObjectFileFactory() {
  cout << "Mock ObjectFileFactory destructor was called" << endl;
}

ObjectIdentifier ObjectFileFactory::createObject(int type, int x, int y) {
  cout << "Mock ObjectFileFactory CreateObject was called with (" << type
       << ", " << x << ", " << y << ")" << endl;
  ObjectIdentifier oid;
  return oid;
}

void ObjectFileFactory::createComponent(ComponentData data) {
  cout << "Mock ObjectFileFactory createComponent called with (" << data.type
       << ", " << data.name << ", " << data.objectIdentifier.getType() << ", "
       << data.objectIdentifier.getName() << ", "
       << data.objectIdentifier.getId() << ")" << endl;
  cout << "data.args: ";
  for (vector<string>::iterator it = data.args.begin(); it != data.args.end();
       ++it) {
    cout << ", " << (*it).c_str();
  }
  cout << endl;
}

void ObjectFileFactory::setup() {
  cout << "Mock ObjectFileFactory Setup was called." << endl;
}
void ObjectFileFactory::tearDown() {
  cout << "Mock ObjectFileFactory TearDown was called." << endl;
}
void ObjectFileFactory::update() {
  cout << "Mock ObjectFileFactory Update was called." << endl;
}
void ObjectFileFactory::input(Input i) {
  cout << "Mock ObjectFileFactory Input was called with " << i.getInput()
       << endl;
}
void ObjectFileFactory::physics() {
  cout << "Mock ObjectFileFactory Physics was called." << endl;
}
int ObjectFileFactory::getIsDirty() {
  cout << "Mock ObjectFileFactory GetIsDirty was called." << endl;
  return 1;
}
void ObjectFileFactory::render() {
  cout << "Mock ObjectFileFactory Render was called." << endl;
}
void ObjectFileFactory::clearAllComponents() {
  cout << "Mock ObjectFileFactory ClearAllComponents was called." << endl;
}
void ObjectFileFactory::removeComponent(int type, string name,
                                        ObjectIdentifier oid) {
  cout << "Mock ObjectFileFactory removeComponent called with (" << type << ", "
       << name.c_str() << ", " << oid.getType() << ", " << oid.getName() << ", "
       << oid.getId() << ")" << endl;
}

void ObjectFileFactory::removeObject(ObjectIdentifier oid) {
  cout << "Mock ObjectFileFactory removeObject called with (" << oid.getType()
       << ", " << oid.getName() << ", " << oid.getId() << ")" << endl;
}
vector<shared_ptr<Component>>
ObjectFileFactory::getComponentsByObjectAndComponentType(int type, string name,
                                                         int otype,
                                                         string oname,
                                                         int oid) {
  cout << "Mock ObjectFileFactory getComponentsByObjectAndComponentType "
          "called with ("
       << type << ", " << name.c_str() << ", " << otype << ", " << oname.c_str()
       << ", " << oid << ")" << endl;
  vector<shared_ptr<Component>> retval;
  return retval;
  ;
}
vector<shared_ptr<Component>>
ObjectFileFactory::getComponentsByObjectAndComponentType(int type, string name,
                                                         int otype,
                                                         string oname) {
  cout << "Mock ObjectFileFactory getComponentsByObjectAndComponentType "
          "called with ("
       << type << ", " << name.c_str() << ", " << otype << ", " << oname.c_str()
       << ")" << endl;
  vector<shared_ptr<Component>> retval;
  return retval;
  ;
}
vector<shared_ptr<Component>>
ObjectFileFactory::getComponentsByObjectAndComponentType(int type, string name,
                                                         ObjectIdentifier oid) {
  cout << "Mock ObjectFileFactory getComponentsByObjectAndComponentType "
          "called with ("
       << type << ", " << name.c_str() << ", " << oid.getType() << ", "
       << oid.getName() << ", " << oid.getId() << ")" << endl;
  vector<shared_ptr<Component>> retval;
  return retval;
  ;
}
shared_ptr<Component> ObjectFileFactory::getComponentByObjectAndComponentType(
    int type, string name, ObjectIdentifier oid) {
  cout << "Mock ObjectFileFactory getComponentByObjectAndComponentType "
          "called with ("
       << type << ", " << name.c_str() << ", " << oid.getType() << ", "
       << oid.getName() << ", " << oid.getId() << ")" << endl;
  shared_ptr<Component> retval;
  return retval;
  ;
}
vector<shared_ptr<Component>> ObjectFileFactory::getComponentsByObject(
    ObjectIdentifier oid) {
  cout << "Mock ObjectFileFactory getComponentsByObject called with ("
       << oid.getType() << ", " << oid.getName() << ", " << oid.getId() << ")"
       << endl;
  vector<shared_ptr<Component>> retval;
  return retval;
  ;
}
void ObjectFileFactory::deleteComponents() {
  cout << "Mock ObjectFileFactory deleteComponents was called." << endl;
}
