#include "scene_manager.hpp"
#include "engine.hpp"
#include <iostream>

SceneManager::SceneManager(int initialObjectId) {
  std::cout << "Mock SceneManager constructor called with (" << initialObjectId
            << ")" << std::endl;
}

SceneManager::~SceneManager() {
  std::cout << "Mock SceneManager destructor called" << std::endl;
}

void SceneManager::setup() {
  std::cout << "Mock SceneManager setup called" << std::endl;
}

void SceneManager::update() {
  std::cout << "Mock SceneManager update called" << std::endl;
  Engine::exit();
}

