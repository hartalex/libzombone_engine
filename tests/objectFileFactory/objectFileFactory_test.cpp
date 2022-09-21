#include <memory>
#define config mock
#include "zombone_engine/ObjectFileFactory.hpp"
#include "zombone_engine/FlatObjectFileParser.hpp"

#include <stdlib.h>

#include "GameComponentFactory.hpp"

using namespace std;
using namespace zombone_engine;

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  ObjectFileFactory off(make_unique<GameComponentFactory>(), make_unique<FlatObjectFileParser>(), argv[1]);
  return EXIT_SUCCESS;
}
