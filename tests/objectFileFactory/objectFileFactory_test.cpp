#define config mock
#include "zombone_engine/ObjectFileFactory.hpp"

#include <stdlib.h>

#include "GameComponentFactory.hpp"
using namespace std;
using namespace zombone_engine;

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  ObjectFileFactory off(make_unique<GameComponentFactory>(), argv[1]);
  return EXIT_SUCCESS;
}
