#ifndef HEADER_ENGINE
#define HEADER_ENGINE
#include <vector>

#include "scene_manager.hpp"

class Engine {
 public:
  Engine(int initialObjectId);
  virtual ~Engine();
  virtual void loop();
  virtual void exit();

 private:
  SceneManager sceneManager;
  static bool isRunning;
};

#endif
