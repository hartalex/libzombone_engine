#ifndef HEADER_GAME_COMPONENT_FACTORY
#define HEADER_GAME_COMPONENT_FACTORY

#include <memory>

#include "ComponentData.hpp"
#include "ComponentFactory.hpp"
#include "component.hpp"
using namespace std;

class GameComponentFactory : public ComponentFactory {
 public:
  GameComponentFactory();
  virtual ~GameComponentFactory();
  virtual shared_ptr<Component> createComponent(ComponentData data) override;
};
#endif
