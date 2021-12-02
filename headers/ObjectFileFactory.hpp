#ifndef HEADER_OBJECT_FILE_FACTORY
#define HEADER_OBJECT_FILE_FACTORY
#include <memory>
#include <string>
#include <vector>

#include "ComponentFactory.hpp"
#include "ObjectData.hpp"
#include "ObjectFactory.hpp"
#include "ObjectIdentifier.hpp"
#include "input.hpp"

export class ObjectFileFactory : public ObjectFactory {
 public:
  ObjectFileFactory(std::unique_ptr<ComponentFactory> componentFactory,
                    std::string fileName);
  virtual ~ObjectFileFactory();
  virtual void createComponent(ComponentData) override;
  virtual ObjectIdentifier createObject(int type, int x, int y) override;
  virtual void setup() override;
  virtual void tearDown() override;
  virtual void update() override;
  virtual void input(Input) override;
  virtual void physics() override;
  virtual int getIsDirty() override;
  virtual void render() override;
  virtual void clearAllComponents() override;
  virtual void removeComponent(int componentType, std::string componentName,
                               ObjectIdentifier objectIdentifier) override;
  virtual void removeObject(ObjectIdentifier objectIdentifier) override;
  virtual std::vector<std::shared_ptr<Component>>
  getComponentsByObjectAndComponentType(int componentType,
                                        std::string componentName,
                                        int objectType, std::string objectName,
                                        int objectId) override;
  virtual std::vector<std::shared_ptr<Component>>
  getComponentsByObjectAndComponentType(int componentType,
                                        std::string componentName,
                                        int objectType,
                                        std::string objectName) override;
  virtual std::vector<std::shared_ptr<Component>>
  getComponentsByObjectAndComponentType(
      int componentType, std::string componentName,
      ObjectIdentifier objectIdentifier) override;
  virtual std::shared_ptr<Component> getComponentByObjectAndComponentType(
      int componentType, std::string componentName,
      ObjectIdentifier objectIdentifier) override;
  virtual std::vector<std::shared_ptr<Component>> getComponentsByObject(
      ObjectIdentifier objectIdentifier) override;

 private:
  std::vector<ObjectData> objects;
  std::unique_ptr<ComponentFactory> const componentFactory;
  std::vector<std::shared_ptr<Component>> components;
  int nextObjectId;
  void deleteComponents();
};

#endif
