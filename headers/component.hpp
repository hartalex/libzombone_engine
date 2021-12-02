#ifndef HEADER_COMPONENT
#define HEADER_COMPONENT

#include <time.h>

#include <memory>
#include <string>

#include "ObjectIdentifier.hpp"
#include "input.hpp"
/* #include "types.hpp" */

export class Component {
 public:
  Component(int componentType, std::string componentName,
            ObjectIdentifier objectIdentifier);
  Component(int componentType, std::string componentName);
  virtual ~Component();
  virtual void setup();
  virtual void tearDown();
  virtual void input(Input);
  virtual void update();
  virtual void render();
  virtual void collide(ObjectIdentifier objectIdentifier);
  virtual void physics();
  int getType() const;
  std::string getName() const;
  int getObjectType() const;
  std::string getObjectName() const;
  void removeComponent(int type, std::string name);
  int isRemoved() const;
  void remove();
  int isSetup() const;
  int getIsDirty() const;
  ObjectIdentifier getObjectIdentifier() const;

 private:
  int componentType;
  std::string componentName;
  ObjectIdentifier objectIdentifier;
  int removed;

 protected:
  int setuped;
  int isDirty;
  time_t initialTime;

  double getTicks() const;
  void setIsDirty(int i);
};

#endif
