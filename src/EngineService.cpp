#include "zombone_engine/EngineService.hpp"

#include <cstddef>
#include <memory>
#include <stdexcept>

#include "zombone_engine/engine.hpp"
using namespace std;

namespace zombone_engine {

shared_ptr<Engine> EngineService::engine(nullptr);

Engine &EngineService::getEngine() {
  if (engine == NULL) {
    throw logic_error("Engine is not yet initialized");
  }
  return *engine;
}

void EngineService::setEngine(shared_ptr<Engine> e) { engine = e; }

}  // namespace zombone_engine
