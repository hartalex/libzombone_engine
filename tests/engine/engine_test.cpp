#define config mock
#include "engine.hpp"

#include <stdlib.h>

#include <iostream>

#include "EngineService.hpp"
using namespace std;

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  std::shared_ptr<Engine> engine = std::make_shared<Engine>(0);
  EngineService::setEngine(engine);
  cout << "Calling getScreenHeight return value is "
       << engine->getScreenHeight() << endl;
  cout << "Calling getScreenWidth return value is " << engine->getScreenWidth()
       << endl;
  cout << "Calling getInput return value is " << (int)engine->getInput()
       << endl;
  cout << "Calling getInputError return value is "
       << (int)engine->getInputError() << endl;
  cout << "Calling clearScreen" << endl;
  engine->clearScreen();
  cout << "Calling refreshScreen" << endl;
  engine->refreshScreen();

  engine->loop();
  return EXIT_SUCCESS;
}
