#define config mock
#include "zombone_engine/scene_manager.hpp"

#include <iostream>
#include <memory>

#include "GameComponentFactory.hpp"
#include "zombone_engine/EngineService.hpp"
#include "zombone_engine/ObjectFactoryService.hpp"
#include "zombone_engine/ObjectFileFactory.hpp"
#include "zombone_engine/FlatObjectFileParser.hpp"
#include "zombone_engine/engine.hpp"
using namespace std;
using namespace zombone_engine;

int main(int argc, char *argv[]) {
  (void)argc;
  ObjectFactoryService::setObjectFactory(make_shared<ObjectFileFactory>(
      make_unique<GameComponentFactory>(), make_unique<FlatObjectFileParser>(), "./objects.dat"));
  EngineService::setEngine(std::make_shared<Engine>(0));
  EngineService::setEngine(make_shared<Engine>(0));
  SceneManager sceneManager(0);
  sceneManager.setup();
  sceneManager.update();
  sceneManager.setScene(1);
  return EXIT_SUCCESS;
}
