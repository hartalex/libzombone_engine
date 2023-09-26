#ifndef HEADER_COMPONENT_FACTORY
#define HEADER_COMPONENT_FACTORY

#include <memory>

#include "Component.hpp"
#include "ComponentData.hpp"
using namespace std;

namespace zombone_engine {

class ComponentFactory {
 public:
  virtual ~ComponentFactory(){};
  virtual shared_ptr<Component> createComponent(ComponentData data) = 0;
};

}  // namespace zombone_engine

#endif
