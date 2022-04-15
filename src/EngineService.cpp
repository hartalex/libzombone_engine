#include "EngineService.hpp"

#include <cstddef>
#include <memory>
#include <stdexcept>

#include "engine.hpp"
using namespace std;

shared_ptr<Engine> EngineService::engine(nullptr);

Engine &EngineService::getEngine() {
  if (engine == NULL) {
    throw logic_error("Engine is not yet initialized");
  }
  return *engine;
}

void EngineService::setEngine(shared_ptr<Engine> e) { engine = e; }
