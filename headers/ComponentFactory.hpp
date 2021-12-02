#ifndef HEADER_COMPONENT_FACTORY
#define HEADER_COMPONENT_FACTORY

#include <memory>

#include "ComponentData.hpp"
#include "component.hpp"

export class ComponentFactory {
 public:
  virtual ~ComponentFactory(){};
  virtual std::shared_ptr<Component> createComponent(ComponentData data) = 0;
};
#endif
