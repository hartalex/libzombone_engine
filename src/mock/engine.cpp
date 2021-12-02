#include "engine.hpp"
#include "scene_manager.hpp"
#include <iostream>

Engine::Engine(int initialObjectId)
    : sceneManager(SceneManager(initialObjectId)) {
  std::cout << "Mock Engine constructor called with " << initialObjectId
            << std::endl;
}

Engine::~Engine() {
  std::cout << "Mock Engine destructor called." << std::endl;
}

void Engine::loop() { std::cout << "Mock Engine Loop was called" << std::endl; }

void Engine::exit() { std::cout << "Mock Engine Exit was called" << std::endl; }

