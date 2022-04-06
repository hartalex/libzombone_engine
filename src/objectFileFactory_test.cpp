#define config mock
#include "ObjectFileFactory.hpp"

#include <stdlib.h>

#include "GameComponentFactory.hpp"
using namespace std;

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  ObjectFileFactory off(make_unique<GameComponentFactory>(), argv[1]);
  return EXIT_SUCCESS;
}
