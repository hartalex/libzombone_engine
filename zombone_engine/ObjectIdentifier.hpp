#ifndef HEADER_OBJECT_IDENTIFIER
#define HEADER_OBJECT_IDENTIFIER

#include <string>
using namespace std;

class ObjectIdentifier {
 public:
  ObjectIdentifier();
  ObjectIdentifier(int type, string name, int id);
  virtual ~ObjectIdentifier();
  virtual int getType() const;
  virtual string getName() const;
  virtual int getId() const;
  virtual void setId(int i);
  bool operator==(const ObjectIdentifier &rhs) const;

 private:
  int type;
  string name;
  int id;
};

#endif
