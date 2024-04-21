#include <gtest/gtest.h>

#include <memory>

#include "MockComponent.hpp"
#include "zombone_engine/Component.hpp"
#include "zombone_engine/ComponentStorage.hpp"
#include "zombone_engine/ObjectIdentifier.hpp"

using namespace zombone_engine;

// test adding a component to storage
// and retrieving it by componentType, componentName and ObjectIdentifier
TEST(ComponentStorage, AddComponent) {
  ComponentStorage cs;
  ObjectIdentifier objectIdentifier{1, "obj name", 1};
  shared_ptr<Component> component =
      std::make_shared<MockComponent>(1, "comp name", objectIdentifier);

  cs.addComponent(component);
  shared_ptr<Component> foundComponent =
      cs.getComponentByObjectAndComponentType(component->getType(),
                                              component->getName(),
                                              component->getObjectIdentifier());

  // Expect equality.
  EXPECT_EQ(component, foundComponent);
}

// test adding a component to storage
// setup component storage should call components setup
TEST(ComponentStorage, SetupComponent) {
  ComponentStorage cs;
  ObjectIdentifier objectIdentifier{1, "obj name", 1};
  shared_ptr<MockComponent> component =
      make_shared<MockComponent>(1, "comp name", objectIdentifier);
  cs.addComponent(component);

  EXPECT_CALL(*component, setup);
  cs.setup();
}
