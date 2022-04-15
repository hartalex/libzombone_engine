#define config mock
#include "scene_manager.hpp"

#include <iostream>
#include <memory>

#include "EngineService.hpp"
#include "GameComponentFactory.hpp"
#include "ObjectFactoryService.hpp"
#include "ObjectFileFactory.hpp"
#include "engine.hpp"
using namespace std;

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
