#ifndef HEADER_ENGINE_SERVICE
#define HEADER_ENGINE_SERVICE
#include <memory>

#include "engine.hpp"
using namespace std;

namespace zombone_engine {

class EngineService {
 public:
  static Engine &getEngine();
  static void setEngine(shared_ptr<Engine> e);

 private:
  static shared_ptr<Engine> engine;
};

}  // namespace zombone_engine

#endif
