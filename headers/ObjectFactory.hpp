#ifndef HEADER_OBJECT_FACTORY
#define HEADER_OBJECT_FACTORY

#include <string>
#include <vector>

#include "ComponentData.hpp"
#include "ObjectIdentifier.hpp"
#include "component.hpp"
#include "input.hpp"

export class ObjectFactory {
 public:
  virtual ~ObjectFactory(){};
  virtual void createComponent(ComponentData) = 0;
  virtual ObjectIdentifier createObject(int type, int x, int y) = 0;
  virtual void setup() = 0;
  virtual void tearDown() = 0;
  virtual void update() = 0;
  virtual void input(Input) = 0;
  virtual void physics() = 0;
  virtual int getIsDirty() = 0;
  virtual void render() = 0;
  virtual void clearAllComponents() = 0;
  virtual void removeComponent(int componentType, std::string componentName,
                               ObjectIdentifier objectIdentifier) = 0;
  virtual void removeObject(ObjectIdentifier objectIdentifier) = 0;
  virtual std::vector<std::shared_ptr<Component>>
  getComponentsByObjectAndComponentType(int componentType,
                                        std::string componentName,
                                        int objectType, std::string objectName,
                                        int objectId) = 0;
  virtual std::vector<std::shared_ptr<Component>>
  getComponentsByObjectAndComponentType(int componentType,
                                        std::string componentName,
                                        int objectType,
                                        std::string objectName) = 0;
  virtual std::vector<std::shared_ptr<Component>>
  getComponentsByObjectAndComponentType(int componentType,
                                        std::string componentName,
                                        ObjectIdentifier objectIdentifier) = 0;
  virtual std::shared_ptr<Component> getComponentByObjectAndComponentType(
      int componentType, std::string componentName,
      ObjectIdentifier objectIdentifier) = 0;
  virtual std::vector<std::shared_ptr<Component>> getComponentsByObject(
      ObjectIdentifier objectIdentifier) = 0;
};

#endif
