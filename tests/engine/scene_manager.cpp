
#include <iostream>

#include "zombone_engine/EngineService.hpp"
using namespace std;

namespace zombone_engine {

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
  EngineService::getEngine().exit();
}

}  // namespace zombone_engine
