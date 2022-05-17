#define config mock
#include <stdlib.h>

#include <iostream>

#include "GameComponentFactory.hpp"
#include "zombone_engine/ObjectFileFactory.hpp"
using namespace std;
using namespace zombone_engine;

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  ObjectFileFactory off(make_unique<GameComponentFactory>(), argv[1]);
  off.setup();
  return EXIT_SUCCESS;
}
