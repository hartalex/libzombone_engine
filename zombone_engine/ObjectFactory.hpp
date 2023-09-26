#ifndef HEADER_OBJECT_FACTORY
#define HEADER_OBJECT_FACTORY

#include <string>
#include <vector>

#include "Component.hpp"
#include "ComponentData.hpp"
#include "ObjectIdentifier.hpp"
#include "input.hpp"
using namespace std;

namespace zombone_engine {

class ObjectFactory {
   public:
    virtual ~ObjectFactory(){};
    virtual void createComponent(ComponentData) = 0;
    virtual ObjectIdentifier createObject(int type) = 0;
    virtual void setup() = 0;
    virtual void tearDown() = 0;
    virtual void update() = 0;
    virtual void input(Input) = 0;
    virtual void physics() = 0;
    virtual int getIsDirty() = 0;
    virtual void render() = 0;
    virtual void clearAllComponents() = 0;
    virtual void removeComponent(int componentType, string componentName,
                                 ObjectIdentifier objectIdentifier) = 0;
    virtual void removeObject(ObjectIdentifier objectIdentifier) = 0;
    virtual vector<shared_ptr<Component>> getComponentsByObjectAndComponentType(
        int componentType, string componentName, int objectType,
        string objectName, int objectId) = 0;
    virtual vector<shared_ptr<Component>> getComponentsByObjectAndComponentType(
        int componentType, string componentName, int objectType,
        string objectName) = 0;
    virtual vector<shared_ptr<Component>> getComponentsByObjectAndComponentType(
        int componentType, string componentName,
        ObjectIdentifier objectIdentifier) = 0;
    virtual vector<shared_ptr<Component>> getComponentsByObject(
        ObjectIdentifier objectIdentifier) = 0;

    virtual shared_ptr<Component> getComponentByObjectAndComponentType(
        int componentType, string componentName,
        ObjectIdentifier objectIdentifier) = 0;

    template <typename T>
    shared_ptr<T> getComponentByObjectAndComponentType(int componentType,
                                                       string componentName,
                                                       int objectType,
                                                       string objectName,
                                                       int objectId) {
        vector<shared_ptr<Component>> foundComponents =
            getComponentsByObjectAndComponentType(
                componentType, componentName, objectType, objectName, objectId);
        if (foundComponents.size() > 0) {
            std::shared_ptr<T> component =
                std::static_pointer_cast<T>(foundComponents[0]);
            return component;
        }
        return nullptr;
    }

    template <typename T>
    shared_ptr<T> getComponentByObjectAndComponentType(
        int componentType, string componentName,
        ObjectIdentifier objectIdentifier) {
        vector<shared_ptr<Component>> foundComponents =
            getComponentsByObjectAndComponentType(componentType, componentName,
                                                  objectIdentifier);
        if (foundComponents.size() > 0) {
            std::shared_ptr<T> component =
                std::static_pointer_cast<T>(foundComponents[0]);
            return component;
        }
        return nullptr;
    }
    template <typename T>
    shared_ptr<T> getComponentByObjectAndComponentType(int componentType,
                                                       string componentName,
                                                       int objectType,
                                                       string objectName) {
        vector<shared_ptr<Component>> foundComponents =
            getComponentsByObjectAndComponentType(componentType, componentName,
                                                  objectType, objectName);
        if (foundComponents.size() > 0) {
            std::shared_ptr<T> component =
                std::static_pointer_cast<T>(foundComponents[0]);
            return component;
        }
        return nullptr;
    }
};

}  // namespace zombone_engine

#endif
