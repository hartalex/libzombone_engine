#define config mock
#include <stdlib.h>

#include <iostream>

#include "GameComponentFactory.hpp"
#include "ObjectFileFactory.hpp"
using namespace std;

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;
  try {
    ObjectFileFactory off(make_unique<GameComponentFactory>(), argv[1]);
  } catch (const exception &e) {
    cout << "Exception caught" << endl;
    cout << e.what() << endl;
  }
  return EXIT_SUCCESS;
}
