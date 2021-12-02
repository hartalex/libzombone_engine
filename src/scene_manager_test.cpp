#define config mock
#include "scene_manager.hpp"

#include "GameComponentFactory.hpp"
#include "ObjectFactoryService.hpp"
#include "ObjectFileFactory.hpp"

std::unique_ptr<ObjectFactory> ObjectFactoryService::objectFactory =
    std::make_unique<ObjectFileFactory>(
        std::make_unique<GameComponentFactory>(), "./objects.dat");

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  SceneManager sceneManager(0);
  sceneManager.setup();
  sceneManager.update();
  sceneManager.setScene(1);
  return EXIT_SUCCESS;
}
