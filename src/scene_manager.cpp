#include "zombone_engine/scene_manager.hpp"

#include <vector>

#include "zombone_engine/EngineService.hpp"
#include "zombone_engine/LoggerService.hpp"
#include "zombone_engine/ObjectFactoryService.hpp"
#include "zombone_engine/engine.hpp"
#include "zombone_engine/input.hpp"

namespace zombone_engine {

SceneManager::SceneManager(int initialObjectId) {
  ObjectFactoryService::getObjectFactory().createObject(initialObjectId);
}

SceneManager::~SceneManager() {}

void SceneManager::setup() { ObjectFactoryService::getObjectFactory().setup(); }

void SceneManager::update() {
  char ch = EngineService::getEngine().getInput();

  if (ch != EngineService::getEngine().getInputError()) {
    Input input = Input(ch);
    ObjectFactoryService::getObjectFactory().input(input);
  }

  ObjectFactoryService::getObjectFactory().update();

  ObjectFactoryService::getObjectFactory().physics();

  if (ObjectFactoryService::getObjectFactory().getIsDirty()) {
    LoggerService::getLogger().info("Rendering");
    EngineService::getEngine().clearScreen();
    ObjectFactoryService::getObjectFactory().render();
    EngineService::getEngine().refreshScreen();
  }
  /* LoggerService::getLogger().info("Scene tick %d",
   * current_scene->getTicks()); */
}

void SceneManager::setScene(int nextObjectId) {
  ObjectFactoryService::getObjectFactory().tearDown();
  ObjectFactoryService::getObjectFactory().clearAllComponents();
  LoggerService::getLogger().debug("Setting Scene to %i", nextObjectId);
  ObjectFactoryService::getObjectFactory().createObject(nextObjectId);
  ObjectFactoryService::getObjectFactory().setup();
}

}  // namespace zombone_engine
