#include <iostream>

#include "engine.hpp"
#include "scene_manager.hpp"
using namespace std;

Engine::Engine(int initialObjectId)
    : sceneManager(SceneManager(initialObjectId)) {
  cout << "Mock Engine constructor called with " << initialObjectId << endl;
}

Engine::~Engine() { cout << "Mock Engine destructor called." << endl; }

void Engine::loop() { cout << "Mock Engine Loop was called" << endl; }

void Engine::exit() { cout << "Mock Engine Exit was called" << endl; }

int Engine::getScreenHeight() {
  cout << "Mock Engine getScreenHeight was called" << endl;
  return 0;
}
int Engine::getScreenWidth() {
  cout << "Mock Engine getScreenWidth was called" << endl;
  return 0;
}
char Engine::getInput() {
  cout << "Mock Engine getInputwas called" << endl;
  return 'c';
}
char Engine::getInputError() {
  cout << "Mock Engine getInputError was called" << endl;
  return 0;
}
void Engine::clearScreen() {
  cout << "Mock Engine clearScreen was called" << endl;
};
void Engine::refreshScreen() {
  cout << "Mock Engine refreshScreen was called" << endl;
};
