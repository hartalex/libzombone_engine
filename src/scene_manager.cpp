#include <vector>
#include <zombone_engine/EngineService.hpp>
#include <zombone_engine/LoggerService.hpp>
#include <zombone_engine/ObjectFactoryService.hpp>
#include <zombone_engine/engine.hpp>
#include <zombone_engine/input.hpp>
#include <zombone_engine/scene_manager.hpp>

#include "zombone_engine/ComponentStorageService.hpp"

namespace zombone_engine {

SceneManager::SceneManager(int initialObjectId) {
  ObjectFactoryService::getObjectFactory().createObject(initialObjectId);
}

SceneManager::~SceneManager() {}

void SceneManager::setup() {
  ComponentStorageService::getComponentStorage().setup();
}

void SceneManager::update() {
  char ch = EngineService::getEngine().getInput();

  if (ch != EngineService::getEngine().getInputError()) {
    Input input = Input(ch);
    ComponentStorageService::getComponentStorage().input(input);
  }

  ComponentStorageService::getComponentStorage().update();

  ComponentStorageService::getComponentStorage().physics();

  if (ComponentStorageService::getComponentStorage().getIsDirty()) {
    LoggerService::getLogger().info("Rendering");
    EngineService::getEngine().clearScreen();
    ComponentStorageService::getComponentStorage().render();
    EngineService::getEngine().refreshScreen();
  }
  /* LoggerService::getLogger().info("Scene tick %d",
   * current_scene->getTicks()); */
}

void SceneManager::setScene(int nextObjectId) {
  ComponentStorageService::getComponentStorage().tearDown();
  ComponentStorageService::getComponentStorage().clearAllComponents();
  LoggerService::getLogger().debug("Setting Scene to %i", nextObjectId);
  ObjectFactoryService::getObjectFactory().createObject(nextObjectId);
  ComponentStorageService::getComponentStorage().setup();
}

}  // namespace zombone_engine
