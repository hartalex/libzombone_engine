#ifndef HEADER_COMPONENT
#define HEADER_COMPONENT

#include <time.h>

#include <memory>
#include <string>

#include "ObjectIdentifier.hpp"
#include "input.hpp"
using namespace std;

namespace zombone_engine {

class Component {
 public:
  Component(int componentType, string componentName,
            ObjectIdentifier objectIdentifier);
  Component(int componentType, string componentName);
  virtual ~Component();
  virtual void setup();
  virtual void tearDown();
  virtual void input(Input);
  virtual void update();
  virtual void render();
  virtual void collide(ObjectIdentifier objectIdentifier);
  virtual void physics();
  int getType() const;
  string getName() const;
  int getObjectType() const;
  string getObjectName() const;
  void removeComponent(int type, string name);
  int isRemoved() const;
  void remove();
  int isSetup() const;
  int getIsDirty() const;
  const ObjectIdentifier& getObjectIdentifier() const;

 private:
  int componentType;
  string componentName;
  ObjectIdentifier objectIdentifier;
  int removed;

 protected:
  int setuped;
  int isDirty;
  time_t initialTime;

  double getTicks() const;
  void setIsDirty(int i);
};

}  // namespace zombone_engine

#endif
