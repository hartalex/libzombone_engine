#define config mock
#include "engine.hpp"
#include <stdlib.h>

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  Engine engine(0);
  engine.loop();
  return EXIT_SUCCESS;
}
