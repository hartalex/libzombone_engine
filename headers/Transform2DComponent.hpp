#ifndef HEADER_TRANSFORM2D_COMPONENT
#define HEADER_TRANSFORM2D_COMPONENT

#include <string>

#include "component.hpp"
#include "types.hpp"

class Transform2DComponent : public Component {
 public:
  Transform2DComponent(std::string name, ObjectIdentifier objectIdentifier)
      : Component(TYPE_COMPONENT_TRANSFORM_2D, name, objectIdentifier),
        x(0),
        y(0),
        previous_x(0),
        previous_y(0),
        hasMoved(0){};
  Transform2DComponent(std::string name, ObjectIdentifier objectIdentifier,
                       int x, int y)
      : Component(TYPE_COMPONENT_TRANSFORM_2D, name, objectIdentifier),
        x(x),
        y(y),
        previous_x(x),
        previous_y(y),
        hasMoved(0){};
  Transform2DComponent(std::string name, int x, int y)
      : Component(TYPE_COMPONENT_TRANSFORM_2D, name),
        x(x),
        y(y),
        previous_x(x),
        previous_y(y),
        hasMoved(0){};
  Transform2DComponent(const Transform2DComponent &t)
      : Component(TYPE_COMPONENT_TRANSFORM_2D, t.getName(),
                  t.getObjectIdentifier()),
        x(t.x),
        y(t.y),
        previous_x(t.previous_x),
        previous_y(t.previous_y),
        hasMoved(0){};
  virtual ~Transform2DComponent() final;
  void move(int, int);
  void move(int, int, int);
  void move(Transform2DComponent &transform);
  void move(Transform2DComponent &transform, int);
  Transform2DComponent unMove();
  void initializeXY(int xx, int yy);
  void setXY(int, int);
  void setXY(Transform2DComponent &transform);
  void setX(int);
  void setY(int);
  int getX() const;
  int getY() const;
  double distance(Transform2DComponent &transform) const;
  int hasMovedThisFrame() const;
  virtual void render() override;

 private:
  int x;
  int y;
  int previous_x;
  int previous_y;
  int hasMoved;
};

static Transform2DComponent UP("direction", 0, -1);
static Transform2DComponent DOWN("direction", 0, 1);
static Transform2DComponent LEFT("direction", -1, 0);
static Transform2DComponent RIGHT("direction", 1, 0);

static Transform2DComponent UPLEFT("direction", -1, -1);
static Transform2DComponent UPRIGHT("direction", 1, -1);
static Transform2DComponent DOWNLEFT("direction", -1, 1);
static Transform2DComponent DOWNRIGHT("direction", 1, 1);

#endif
