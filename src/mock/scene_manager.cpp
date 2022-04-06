#include "scene_manager.hpp"

#include <iostream>

#include "engine.hpp"
using namespace std;

SceneManager::SceneManager(int initialObjectId) {
  cout << "Mock SceneManager constructor called with (" << initialObjectId
       << ")" << endl;
}

SceneManager::~SceneManager() {
  cout << "Mock SceneManager destructor called" << endl;
}

void SceneManager::setup() { cout << "Mock SceneManager setup called" << endl; }

void SceneManager::update() {
  cout << "Mock SceneManager update called" << endl;
  Engine::exit();
}

