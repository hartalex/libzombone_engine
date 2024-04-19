#ifndef HEADER_COMPONENT_STORAGE
#define HEADER_COMPONENT_STORAGE

#include <string>
#include <vector>

#include "zombone_engine/ComponentData.hpp"
#include "zombone_engine/ObjectIdentifier.hpp"
#include "zombone_engine/component.hpp"
#include "zombone_engine/input.hpp"
using namespace std;

namespace zombone_engine {

class ComponentStorage {
   public:
    ComponentStorage();
    virtual ~ComponentStorage();
    virtual void setup();
    virtual void tearDown();
    virtual void update();
    virtual void input(Input);
    virtual void physics();
    virtual int getIsDirty();
    virtual void render();
    virtual void clearAllComponents();
    virtual void addComponent(shared_ptr<Component> component);
    virtual void removeComponent(int componentType, string componentName,
                                 ObjectIdentifier objectIdentifier);
    virtual void removeObject(ObjectIdentifier objectIdentifier);
    virtual vector<shared_ptr<Component>> getComponentsByObjectAndComponentType(
        int componentType, string componentName, int objectType,
        string objectName, int objectId);
    virtual vector<shared_ptr<Component>> getComponentsByObjectAndComponentType(
        int componentType, string componentName, int objectType,
        string objectName);
    virtual vector<shared_ptr<Component>> getComponentsByObjectAndComponentType(
        int componentType, string componentName,
        ObjectIdentifier objectIdentifier);
    virtual shared_ptr<Component> getComponentByObjectAndComponentType(
        int componentType, string componentName,
        ObjectIdentifier objectIdentifier);
    virtual vector<shared_ptr<Component>> getComponentsByObject(
        ObjectIdentifier objectIdentifier);
    void deleteComponents();

   private:
    vector<shared_ptr<Component>> components;
};

}  // namespace zombone_engine

#endif
