#include "zombone_engine/engine.hpp"

#include <stdlib.h>

#include <chrono>
#include <iostream>
#include <thread>

#include "zombone_engine/LoggerService.hpp"
#include "zombone_engine/scene_manager.hpp"
using namespace std;

namespace zombone_engine {

bool Engine::isRunning = true;

Engine::Engine(int initialObjectId)
    : sceneManager(SceneManager(initialObjectId)) {
  LoggerService::getLogger().debug("Setup");
}

Engine::~Engine() { LoggerService::getLogger().debug("TearDown"); }

void Engine::loop() {
  sceneManager.setup();
  while (isRunning) {
    sceneManager.update();
    this_thread::sleep_for(chrono::microseconds(1000));
  }
}

void Engine::exit() { isRunning = false; }

int Engine::getScreenHeight() { return 0; }
int Engine::getScreenWidth() { return 0; }
char Engine::getInput() { return 0; }
char Engine::getInputError() { return 0; }
void Engine::clearScreen() {};
void Engine::refreshScreen() {};

}  // namespace zombone_engine
