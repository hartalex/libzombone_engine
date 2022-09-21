#define config mock
#include <stdlib.h>

#include <iostream>

#include "GameComponentFactory.hpp"
#include "zombone_engine/ObjectFileFactory.hpp"
#include "zombone_engine/FlatObjectFileParser.hpp"
using namespace std;
using namespace zombone_engine;

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  ObjectFileFactory off(make_unique<GameComponentFactory>(), make_unique<FlatObjectFileParser>(), argv[1]);
  off.update();
  return EXIT_SUCCESS;
}
