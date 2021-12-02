#ifndef HEADER_SCENE_MANAGER
#define HEADER_SCENE_MANAGER

export class SceneManager {
 public:
  SceneManager(int initialObjectId);
  ~SceneManager();
  void update();
  static void setScene(int nextObjectId);
  static void setup();
};

#endif
