#ifndef HEADER_ENGINE
#define HEADER_ENGINE
#include <vector>

#include "scene_manager.hpp"

namespace zombone_engine {

class Engine {
 public:
  Engine(int initialObjectId);
  virtual ~Engine();
  virtual void loop();
  virtual void exit();
  virtual int getScreenHeight();
  virtual int getScreenWidth();
  virtual char getInput();
  virtual char getInputError();
  virtual void clearScreen();
  virtual void refreshScreen();

 private:
  SceneManager sceneManager;
  static bool isRunning;
};

}  // namespace zombone_engine

#endif
