#include "engine.hpp"

#include <iostream>

#include "scene_manager.hpp"
using namespace std;

Engine::Engine(int initialObjectId)
    : sceneManager(SceneManager(initialObjectId)) {
  cout << "Mock Engine constructor called with " << initialObjectId << endl;
}

Engine::~Engine() { cout << "Mock Engine destructor called." << endl; }

void Engine::loop() { cout << "Mock Engine Loop was called" << endl; }

void Engine::exit() { cout << "Mock Engine Exit was called" << endl; }

