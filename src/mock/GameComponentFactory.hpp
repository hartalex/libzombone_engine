#ifndef HEADER_GAME_COMPONENT_FACTORY
#define HEADER_GAME_COMPONENT_FACTORY

#include "ComponentData.hpp"
#include "ComponentFactory.hpp"
#include "component.hpp"
#include <memory>

class GameComponentFactory : public ComponentFactory {
public:
  GameComponentFactory();
  virtual ~GameComponentFactory();
  virtual std::shared_ptr<Component>
  createComponent(ComponentData data) override;
};
#endif
