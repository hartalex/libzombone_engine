#include <gtest/gtest.h>

#include <memory>

#include "MockComponent.hpp"
#include "zombone_engine/Component.hpp"
#include "zombone_engine/ComponentStorage.hpp"
#include "zombone_engine/ObjectIdentifier.hpp"

using namespace zombone_engine;
using testing::Return;
int TRUE = 1;
int FALSE = 0;

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

  ON_CALL(*component, isRemoved).WillByDefault(Return(FALSE));
  ON_CALL(*component, isSetup).WillByDefault(Return(FALSE));
  EXPECT_CALL(*component, setup);
  cs.setup();
}

// test adding a component to storage
// setup component storage should not call components if it's already setup
TEST(ComponentStorage, SetupComponentThatAreAlreadySetup) {
  ComponentStorage cs;
  ObjectIdentifier objectIdentifier{1, "obj name", 1};
  shared_ptr<MockComponent> component =
      make_shared<MockComponent>(1, "comp name", objectIdentifier);
  cs.addComponent(component);

  ON_CALL(*component, isRemoved).WillByDefault(Return(FALSE));
  ON_CALL(*component, isSetup).WillByDefault(Return(TRUE));
  (*component).setup();

  EXPECT_CALL(*component, setup).Times(0);
  cs.setup();
}

// test adding a component to storage
// setup component storage should not call components if it's removed
TEST(ComponentStorage, SetupComponentThatIsRemoved) {
  ComponentStorage cs;
  ObjectIdentifier objectIdentifier{1, "obj name", 1};
  shared_ptr<MockComponent> component =
      make_shared<MockComponent>(1, "comp name", objectIdentifier);
  cs.addComponent(component);

  ON_CALL(*component, isRemoved).WillByDefault(Return(TRUE));
  ON_CALL(*component, isSetup).WillByDefault(Return(FALSE));
  (*component).setup();

  EXPECT_CALL(*component, setup).Times(0);
  cs.setup();
}

// test adding a component to storage
// tearDown component storage should call components tearDown if component is
// setup
TEST(ComponentStorage, TearDownComponent) {
  ComponentStorage cs;
  ObjectIdentifier objectIdentifier{1, "obj name", 1};
  shared_ptr<MockComponent> component =
      make_shared<MockComponent>(1, "comp name", objectIdentifier);

  ON_CALL(*component, isRemoved).WillByDefault(Return(FALSE));
  ON_CALL(*component, isSetup).WillByDefault(Return(TRUE));
  cs.addComponent(component);

  EXPECT_CALL(*component, tearDown).Times(1);
  cs.tearDown();
}
