#include "zombone_engine/ObjectFileFactory.hpp"

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "zombone_engine/ComponentFactory.hpp"
#include "zombone_engine/LoggerService.hpp"
#include "zombone_engine/ObjectData.hpp"
#include "zombone_engine/ObjectFileParser.hpp"
#include "zombone_engine/ObjectIdentifier.hpp"
#include "zombone_engine/component.hpp"

using namespace std;

namespace zombone_engine {


ObjectFileFactory::ObjectFileFactory(
    unique_ptr<ComponentFactory> componentFactory,
    unique_ptr<ObjectFileParser> objectFileParser, string fileName)
    : componentFactory(move(componentFactory)),
      objectFileParser(move(objectFileParser)) {
  nextObjectId = 0;
  LoggerService::getLogger().debug("Opening Object File '%s'",
                                   fileName.c_str());
  fstream inputFile(fileName, ios::in);
  if (inputFile.is_open()) {
    objects = this->objectFileParser->parse(inputFile);

    LoggerService::getLogger().debug("Closing Object File '%s'",
                                     fileName.c_str());
    inputFile.close();
  } else {
    LoggerService::getLogger().warn("Unable to Open Object File '%s'",
                                    fileName.c_str());
  }
}

ObjectFileFactory::~ObjectFileFactory() {}

ObjectIdentifier ObjectFileFactory::createObject(int type) {
  ObjectIdentifier oid;
  LoggerService::getLogger().info("Creating Object of type %i, %i", type,
                                  nextObjectId);
  vector<ObjectData>::iterator it = objects.begin();
  while (it != objects.end() && (*it).type != type) {
    ++it;
  }
  if (it != objects.end()) {
    ObjectData od = *it;

    for (vector<ComponentData>::iterator iit = od.components.begin();
         iit != od.components.end(); ++iit) {
      (*iit).objectIdentifier.setId(nextObjectId);
      createComponent(*iit);
    }
    oid = ObjectIdentifier(od.type, od.name, nextObjectId);
    nextObjectId++;
  } else {
    LoggerService::getLogger().info("Generic Object Type %i Not Found", type);
  }
  return oid;
}

void ObjectFileFactory::createComponent(ComponentData data) {
  shared_ptr<Component> component = componentFactory->createComponent(data);
  if (component) {
    LoggerService::getLogger().info("Creating component of Type %i", data.type);
    components.push_back(component);
  } else {
    LoggerService::getLogger().info("Unable to create component %i", data.type);
  }
}

void ObjectFileFactory::setup() {
  vector<shared_ptr<Component>> tmpComponents = components;
  for (vector<shared_ptr<Component>>::iterator cit = tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 0) {
      (*cit)->setup();
    }
  }
  deleteComponents();
}
void ObjectFileFactory::tearDown() {
  for (vector<shared_ptr<Component>>::iterator cit = components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup()) {
      (*cit)->tearDown();
    }
  }
  deleteComponents();
}
void ObjectFileFactory::update() {
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

void ObjectFileFactory::input(Input inputData) {
  vector<shared_ptr<Component>> tmpComponents = components;
  for (vector<shared_ptr<Component>>::iterator cit = tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 1) {
      (*cit)->input(inputData);
    }
  }
  deleteComponents();
}

void ObjectFileFactory::physics() {
  vector<shared_ptr<Component>> tmpComponents = components;
  for (vector<shared_ptr<Component>>::iterator cit = tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 1) {
      (*cit)->physics();
    }
  }
  deleteComponents();
}
int ObjectFileFactory::getIsDirty() {
  int isDirty = 0;
  for (vector<shared_ptr<Component>>::iterator cit = components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 1) {
      isDirty += (*cit)->getIsDirty();
    }
  }
  return isDirty;
}
void ObjectFileFactory::render() {
  vector<shared_ptr<Component>> tmpComponents = components;
  for (vector<shared_ptr<Component>>::iterator cit = tmpComponents.begin();
       cit != tmpComponents.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 && (*cit)->isSetup() == 1) {
      (*cit)->render();
    }
  }
  deleteComponents();
}
void ObjectFileFactory::clearAllComponents() { components.clear(); }

vector<shared_ptr<Component>>
ObjectFileFactory::getComponentsByObjectAndComponentType(
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

shared_ptr<Component> ObjectFileFactory::getComponentByObjectAndComponentType(
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
ObjectFileFactory::getComponentsByObjectAndComponentType(int componentType,
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
ObjectFileFactory::getComponentsByObjectAndComponentType(int componentType,
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

void ObjectFileFactory::removeComponent(int componentType, string componentName,
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
void ObjectFileFactory::removeObject(ObjectIdentifier objectIdentifier) {
  for (vector<shared_ptr<Component>>::iterator cit = components.begin();
       cit != components.end(); ++cit) {
    if (*cit != 0 && (*cit)->isRemoved() == 0 &&
        (*cit)->getObjectIdentifier() == objectIdentifier) {
      (*cit)->remove();
    }
  }
}

void ObjectFileFactory::deleteComponents() {
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

vector<shared_ptr<Component>> ObjectFileFactory::getComponentsByObject(
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
