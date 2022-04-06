#include "engine.hpp"

#include <ncurses.h>
#include <stdlib.h>

#include <chrono>
#include <iostream>
#include <thread>

#include "LoggerService.hpp"
#include "scene_manager.hpp"
using namespace std;

bool Engine::isRunning = true;

Engine::Engine(int initialObjectId)
    : sceneManager(SceneManager(initialObjectId)) {
  LoggerService::getLogger().debug("Setup");

  // Initialize NCurses
  initscr();
  const int ret_start_color = start_color();
  if (ret_start_color == ERR) {
    cerr << "Error calling start_color()" << endl;
    std::exit(1);
  }
  const int ret_cbreak = cbreak();
  if (ret_cbreak == ERR) {
    cerr << "Error calling cbreak()" << endl;
    std::exit(1);
  }
  const int ret_noecho = noecho();
  if (ret_noecho == ERR) {
    cerr << "Error calling noecho()" << endl;
    std::exit(1);
  }
  const int ret_curs_set = curs_set(0);
  if (ret_curs_set == ERR) {
    cerr << "Error calling curs_set()" << endl;
    std::exit(1);
  }
  const int ret_keypad = keypad(stdscr, true);
  if (ret_keypad == ERR) {
    cerr << "Error calling keypad()" << endl;
    std::exit(1);
  }
  const int ret_nodelay = nodelay(stdscr, true);
  if (ret_nodelay == ERR) {
    cerr << "Error calling nodelay()" << endl;
    std::exit(1);
  }
}

Engine::~Engine() {
  LoggerService::getLogger().debug("TearDown");
  const int ret = endwin();
  if (ret == ERR) {
    cerr << "Error calling endwin()" << endl;
    std::exit(1);
  }
}

void Engine::loop() {
  sceneManager.setup();
  while (isRunning) {
    sceneManager.update();
    this_thread::sleep_for(chrono::microseconds(1000));
  }
}

void Engine::exit() { isRunning = false; }
