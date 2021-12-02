#include "scene_manager.hpp"
#include <ncurses.h>
#include <vector>

#include "LoggerService.hpp"
#include "ObjectFactoryService.hpp"
#include "engine.hpp"
#include "input.hpp"

SceneManager::SceneManager(int initialObjectId) {
  ObjectFactoryService::getObjectFactory().createObject(initialObjectId, 0, 0);
}

SceneManager::~SceneManager() {}

void SceneManager::setup() { ObjectFactoryService::getObjectFactory().setup(); }

void SceneManager::update() {

  char ch = getch();

  if (ch != ERR) {
    Input input = Input(ch);
    ObjectFactoryService::getObjectFactory().input(input);
  }

  ObjectFactoryService::getObjectFactory().update();

  ObjectFactoryService::getObjectFactory().physics();

  if (ObjectFactoryService::getObjectFactory().getIsDirty()) {
    LoggerService::getLogger().info("Rendering");
    clear();
    ObjectFactoryService::getObjectFactory().render();
    refresh();
  }
  /* LoggerService::getLogger().info("Scene tick %d",
   * current_scene->getTicks()); */
}

void SceneManager::setScene(int nextObjectId) {
  ObjectFactoryService::getObjectFactory().tearDown();
  ObjectFactoryService::getObjectFactory().clearAllComponents();
  LoggerService::getLogger().debug("Setting Scene to %i", nextObjectId);
  ObjectFactoryService::getObjectFactory().createObject(nextObjectId, 0, 0);
  ObjectFactoryService::getObjectFactory().setup();
}
