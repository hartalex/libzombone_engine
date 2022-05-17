#define config mock
#include "zombone_engine/scene_manager.hpp"

#include <iostream>
#include <memory>

#include "GameComponentFactory.hpp"
#include "zombone_engine/EngineService.hpp"
#include "zombone_engine/ObjectFactoryService.hpp"
#include "zombone_engine/ObjectFileFactory.hpp"
#include "zombone_engine/engine.hpp"
using namespace std;
using namespace zombone_engine;

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  ObjectFactoryService::setObjectFactory(std::make_shared<ObjectFileFactory>(
      std::make_unique<GameComponentFactory>(), "./objects.dat"));
  EngineService::setEngine(std::make_shared<Engine>(0));
  SceneManager sceneManager(0);
  sceneManager.setup();
  sceneManager.update();
  sceneManager.setScene(1);
  return EXIT_SUCCESS;
}
