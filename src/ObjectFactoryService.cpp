#include "zombone_engine/ObjectFactoryService.hpp"

#include <cstddef>
#include <stdexcept>

#include "zombone_engine/ObjectFactory.hpp"
#include "zombone_engine/ObjectFileFactory.hpp"
using namespace std;

shared_ptr<ObjectFactory> ObjectFactoryService::objectFactory(nullptr);

ObjectFactory &ObjectFactoryService::getObjectFactory() {
  if (objectFactory == NULL) {
    throw logic_error("Object Factory is not yet initialized");
  }
  return *objectFactory;
}

void ObjectFactoryService::setObjectFactory(shared_ptr<ObjectFactory> o) {
  objectFactory = o;
}
