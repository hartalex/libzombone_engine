#define config mock
#include <stdlib.h>

#include <iostream>

#include "GameComponentFactory.hpp"
#include "ObjectFileFactory.hpp"

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  try {
    ObjectFileFactory off(std::make_unique<GameComponentFactory>(), argv[1]);
  } catch (const std::exception &e) {
    std::cout << "Exception caught" << std::endl;
    std::cout << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
