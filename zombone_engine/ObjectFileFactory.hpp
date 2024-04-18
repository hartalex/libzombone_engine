#ifndef HEADER_OBJECT_FILE_FACTORY
#define HEADER_OBJECT_FILE_FACTORY

#include <exception>
#include <expected>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

#include "ComponentFactory.hpp"
#include "ObjectData.hpp"
#include "ObjectFactory.hpp"
#include "ObjectFileParser.hpp"
#include "ObjectIdentifier.hpp"
#include "input.hpp"
using namespace std;

namespace zombone_engine {

class ObjectFileFactory : public ObjectFactory {
   public:
    ObjectFileFactory(unique_ptr<ComponentFactory> componentFactory,
                      unique_ptr<ObjectFileParser> objectFileParser,
                      string fileName);
    virtual ~ObjectFileFactory();
    virtual void createComponent(ComponentData) override;
    virtual ObjectIdentifier createObject(int type) override;
    virtual void setup() override;
    virtual void tearDown() override;
    virtual void update() override;
    virtual void input(Input) override;
    virtual void physics() override;
    virtual int getIsDirty() override;
    virtual void render() override;
    virtual void clearAllComponents() override;
    virtual void removeComponent(int componentType, string componentName,
                                 ObjectIdentifier objectIdentifier) override;
    virtual void removeObject(ObjectIdentifier objectIdentifier) override;
    virtual vector<shared_ptr<Component>> getComponentsByObjectAndComponentType(
        int componentType, string componentName, int objectType,
        string objectName, int objectId) override;
    virtual vector<shared_ptr<Component>> getComponentsByObjectAndComponentType(
        int componentType, string componentName, int objectType,
        string objectName) override;
    virtual vector<shared_ptr<Component>> getComponentsByObjectAndComponentType(
        int componentType, string componentName,
        ObjectIdentifier objectIdentifier) override;
    virtual shared_ptr<Component> getComponentByObjectAndComponentType(
        int componentType, string componentName,
        ObjectIdentifier objectIdentifier) override;
    virtual vector<shared_ptr<Component>> getComponentsByObject(
        ObjectIdentifier objectIdentifier) override;

   private:
    vector<ObjectData> objects;
    unique_ptr<ComponentFactory> const componentFactory;
    unique_ptr<ObjectFileParser> const objectFileParser;
    vector<shared_ptr<Component>> components;
    int nextObjectId;
    void deleteComponents();
    expected<ObjectData, logic_error> findObjectData(int type);
};

}  // namespace zombone_engine

#endif
