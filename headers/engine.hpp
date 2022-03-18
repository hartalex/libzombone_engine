#include <vector>

#include "scene_manager.hpp"

class Engine {
 public:
  Engine(int initialObjectId);
  ~Engine();
  void loop();
  static void exit();

 private:
  SceneManager sceneManager;
  static bool isRunning;
};

