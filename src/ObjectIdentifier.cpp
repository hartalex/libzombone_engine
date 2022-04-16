

#include "ObjectIdentifier.hpp"

#include <string>
using namespace std;

ObjectIdentifier::ObjectIdentifier() : type(-1), name("unknown"), id(-1) {}
ObjectIdentifier::ObjectIdentifier(int type, string name, int id)
    : type(type), name(name), id(id) {}

int ObjectIdentifier::getType() const { return type; }

string ObjectIdentifier::getName() const { return name; }

int ObjectIdentifier::getId() const { return id; }
void ObjectIdentifier::setId(int i) { id = i; }

bool ObjectIdentifier::operator==(const ObjectIdentifier &rhs) const {
  return type == rhs.type && name.compare(rhs.name) == 0 && id == rhs.id;
}
ObjectIdentifier::~ObjectIdentifier() {}
