#ifndef HEADER_GAME_COMPONENT_FACTORY
#define HEADER_GAME_COMPONENT_FACTORY

#include <memory>

#include "zombone_engine/ComponentData.hpp"
#include "zombone_engine/ComponentFactory.hpp"
#include "zombone_engine/component.hpp"
using namespace std;
using namespace zombone_engine;

class GameComponentFactory : public ComponentFactory {
 public:
  GameComponentFactory();
  virtual ~GameComponentFactory();
  virtual shared_ptr<Component> createComponent(ComponentData data) override;
};
#endif
