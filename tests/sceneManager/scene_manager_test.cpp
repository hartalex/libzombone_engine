#define config mock
#include "scene_manager.hpp"

#include <iostream>

#include "GameComponentFactory.hpp"
#include "ObjectFactoryService.hpp"
#include "ObjectFileFactory.hpp"
using namespace std;

unique_ptr<ObjectFactory> ObjectFactoryService::objectFactory =
    make_unique<ObjectFileFactory>(make_unique<GameComponentFactory>(),
                                   "./objects.dat");

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  SceneManager sceneManager(0);
  sceneManager.setup();
  sceneManager.update();
  sceneManager.setScene(1);
  return EXIT_SUCCESS;
}
