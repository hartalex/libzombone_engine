#include <gmock/gmock.h>  // Brings in gMock.

#include "zombone_engine/Component.hpp"
#include "zombone_engine/ObjectIdentifier.hpp"
#include "zombone_engine/input.hpp"

using namespace zombone_engine;

class MockComponent : public Component {
 public:
  MockComponent(int type, string name, ObjectIdentifier objectIdentifier)
      : Component(type, name, objectIdentifier){};
  virtual ~MockComponent(){};
  MOCK_METHOD(void, setup, (), (override));
  MOCK_METHOD(void, tearDown, (), (override));
  MOCK_METHOD(void, input, (Input), (override));
  MOCK_METHOD(void, update, (), (override));
  MOCK_METHOD(void, render, (), (override));
  MOCK_METHOD(void, collide, (ObjectIdentifier objectIdentifier), (override));
  MOCK_METHOD(void, physics, (), (override));
};
