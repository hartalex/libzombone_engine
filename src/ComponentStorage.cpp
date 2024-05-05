#include "zombone_engine/ComponentStorage.hpp"

#include <exception>
#include <expected>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "zombone_engine/Component.hpp"
#include "zombone_engine/ComponentFactory.hpp"
#include "zombone_engine/LoggerService.hpp"
#include "zombone_engine/ObjectFileParser.hpp"
#include "zombone_engine/ObjectIdentifier.hpp"

using namespace std;

namespace zombone_engine {

ComponentStorage::ComponentStorage() {}

ComponentStorage::~ComponentStorage() {}

void ComponentStorage::addComponent(shared_ptr<Component> component) {
  components.push_back(component);
}

void ComponentStorage::setup() {
  vector<shared_ptr<Component>> tmpComponents = components;
  for (vector<shared_ptr<Component>>::iterator cit = tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 0) {
      (*cit)->setup();
    }
  }
  deleteComponents();
}
void ComponentStorage::tearDown() {
  for (vector<shared_ptr<Component>>::iterator cit = components.begin();
       cit != components.end(); ++cit) {
    cout << (*cit) << endl;
    cout << (*cit)->isRemoved() << endl;
    cout << (*cit)->isSetup() << endl;
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup()) {
      (*cit)->tearDown();
    }
  }
  deleteComponents();
}
void ComponentStorage::update() {
  vector<shared_ptr<Component>> tmpComponents = components;
  for (vector<shared_ptr<Component>>::iterator cit = tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 0) {
      (*cit)->setup();
    }
  }
  for (vector<shared_ptr<Component>>::iterator cit = tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 1) {
      (*cit)->update();
    }
  }
  deleteComponents();
}

void ComponentStorage::input(Input inputData) {
  vector<shared_ptr<Component>> tmpComponents = components;
  for (vector<shared_ptr<Component>>::iterator cit = tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 1) {
      (*cit)->input(inputData);
    }
  }
  deleteComponents();
}

void ComponentStorage::physics() {
  vector<shared_ptr<Component>> tmpComponents = components;
  for (vector<shared_ptr<Component>>::iterator cit = tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 1) {
      (*cit)->physics();
    }
  }
  deleteComponents();
}
int ComponentStorage::getIsDirty() {
  int isDirty = 0;
  for (vector<shared_ptr<Component>>::iterator cit = components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 1) {
      isDirty += (*cit)->getIsDirty();
    }
  }
  return isDirty;
}
void ComponentStorage::render() {
  vector<shared_ptr<Component>> tmpComponents = components;
  for (vector<shared_ptr<Component>>::iterator cit = tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 1) {
      (*cit)->render();
    }
  }
  deleteComponents();
}

void ComponentStorage::clearAllComponents() { components.clear(); }

vector<shared_ptr<Component>>
ComponentStorage::getComponentsByObjectAndComponentType(
    int componentType, string componentName,
    ObjectIdentifier objectIdentifier) {
  vector<shared_ptr<Component>> retval;
  for (vector<shared_ptr<Component>>::iterator cit = components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0) {
      if ((*cit)->getType() == componentType &&
          (*cit)->getName().compare(componentName) == 0 &&
          (*cit)->getObjectIdentifier() == objectIdentifier) {
        retval.push_back(*cit);
      }
    }
  }
  return retval;
}

shared_ptr<Component> ComponentStorage::getComponentByObjectAndComponentType(
    int componentType, string componentName,
    ObjectIdentifier objectIdentifier) {
  vector<shared_ptr<Component>> foundComponents =
      getComponentsByObjectAndComponentType(componentType, componentName,
                                            objectIdentifier);
  LoggerService::getLogger().info("Found %i instances of Component %s",
                                  foundComponents.size(),
                                  componentName.c_str());
  if (foundComponents.size() > 0) {
    return foundComponents[0];
  }
  return 0;
}

vector<shared_ptr<Component>>
ComponentStorage::getComponentsByObjectAndComponentType(int componentType,
                                                        string componentName,
                                                        int objectType,
                                                        string objectName,
                                                        int objectId) {
  ObjectIdentifier objectIdentifier(objectType, objectName, objectId);
  vector<shared_ptr<Component>> retval;
  for (vector<shared_ptr<Component>>::iterator cit = components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->getType() == componentType &&
        (*cit)->getName().compare(componentName) == 0 &&
        (*cit)->getObjectIdentifier() == objectIdentifier) {
      retval.push_back(*cit);
    }
  }
  return retval;
}

vector<shared_ptr<Component>>
ComponentStorage::getComponentsByObjectAndComponentType(int componentType,
                                                        string componentName,
                                                        int objectType,
                                                        string objectName) {
  vector<shared_ptr<Component>> retval;
  for (vector<shared_ptr<Component>>::iterator cit = components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->getType() == componentType &&
        (*cit)->getName().compare(componentName) == 0 &&
        (*cit)->getObjectIdentifier().getType() == objectType &&
        (*cit)->getObjectIdentifier().getName().compare(objectName) == 0) {
      retval.push_back(*cit);
    }
  }
  return retval;
}

void ComponentStorage::removeComponent(int componentType, string componentName,
                                       ObjectIdentifier objectIdentifier) {
  for (vector<shared_ptr<Component>>::iterator cit = components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 &&
        (*cit)->getType() == componentType &&
        (*cit)->getName().compare(componentName) == 0 &&
        (*cit)->getObjectIdentifier() == objectIdentifier) {
      (*cit)->remove();
    }
  }
}
void ComponentStorage::removeObject(ObjectIdentifier objectIdentifier) {
  for (vector<shared_ptr<Component>>::iterator cit = components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 &&
        (*cit)->getObjectIdentifier() == objectIdentifier) {
      (*cit)->remove();
    }
  }
}

void ComponentStorage::deleteComponents() {
  for (vector<shared_ptr<Component>>::iterator cit = components.begin();
       cit != components.end();) {
    if (*cit != 0 && (*cit)->isRemoved() == 1) {
      // remove components marked to be removed
      cit = components.erase(cit);
    } else if (*cit == 0) {
      // remove components that are no longer valid
      cit = components.erase(cit);
    } else {
      ++cit;
    }
  }
}

vector<shared_ptr<Component>> ComponentStorage::getComponentsByObject(
    ObjectIdentifier objectIdentifier) {
  vector<shared_ptr<Component>> retval;
  for (vector<shared_ptr<Component>>::iterator cit = components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->getObjectIdentifier() == objectIdentifier) {
      retval.push_back(*cit);
    }
  }
  return retval;
}

}  // namespace zombone_engine
