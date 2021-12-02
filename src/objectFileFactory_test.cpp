#define config mock
#include "GameComponentFactory.hpp"
#include "ObjectFileFactory.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  ObjectFileFactory off(std::make_unique<GameComponentFactory>(), argv[1]);
  return EXIT_SUCCESS;
}
