#ifndef HEADER_COMPONENT
#define HEADER_COMPONENT

#include <time.h>

#include <memory>
#include <string>

#include "ObjectIdentifier.hpp"
#include "input.hpp"
using namespace std;

namespace zombone_engine {
/**
 * @brief The Base Component Object
 *
 * From which all other components inherit from
 */
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
  /**
   * @brief Flag to determine if the component has been setup
   *
   * Used to skip any logic that is not needed or will fail if the component is
   * not yet setup.
   */
  int setuped;
  /**
   * @brief Flag to determine if the component has changed
   *
   * Used to determine if the component should be rerendered
   */
  int isDirty;
  /**
   * @brief The timestamp when the component was created
   *
   * Used to determine how many ticks have passed since the creation of the
   * component
   */
  time_t initialTime;

  double getTicks() const;
  void setIsDirty(int i);
};

}  // namespace zombone_engine

#endif
