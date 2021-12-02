#include "engine.hpp"

#include <chrono>
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <thread>

#include "LoggerService.hpp"
#include "scene_manager.hpp"

bool Engine::isRunning = true;

Engine::Engine(int initialObjectId)
    : sceneManager(SceneManager(initialObjectId)) {
  LoggerService::getLogger().debug("Setup");

  // Initialize NCurses
  initscr();
  const int ret_start_color = start_color();
  if (ret_start_color == ERR) {
    std::cerr << "Error calling start_color()" << std::endl;
    std::exit(1);
  }
  const int ret_cbreak = cbreak();
  if (ret_cbreak == ERR) {
    std::cerr << "Error calling cbreak()" << std::endl;
    std::exit(1);
  }
  const int ret_noecho = noecho();
  if (ret_noecho == ERR) {
    std::cerr << "Error calling noecho()" << std::endl;
    std::exit(1);
  }
  const int ret_curs_set = curs_set(0);
  if (ret_curs_set == ERR) {
    std::cerr << "Error calling curs_set()" << std::endl;
    std::exit(1);
  }
  const int ret_keypad = keypad(stdscr, true);
  if (ret_keypad == ERR) {
    std::cerr << "Error calling keypad()" << std::endl;
    std::exit(1);
  }
  const int ret_nodelay = nodelay(stdscr, true);
  if (ret_nodelay == ERR) {
    std::cerr << "Error calling nodelay()" << std::endl;
    std::exit(1);
  }
}

Engine::~Engine() {
  LoggerService::getLogger().debug("TearDown");
  const int ret = endwin();
  if (ret == ERR) {
    std::cerr << "Error calling endwin()" << std::endl;
    std::exit(1);
  }
}

void Engine::loop() {
  sceneManager.setup();
  while (isRunning) {
    sceneManager.update();
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
  }
}

void Engine::exit() { isRunning = false; }
