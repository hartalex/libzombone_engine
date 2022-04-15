#include "ObjectFactoryService.hpp"

#include <memory>

#include "ObjectFactory.hpp"
using namespace std;

shared_ptr<ObjectFactory> ObjectFactoryService::objectFactory(nullptr);

ObjectFactory &ObjectFactoryService::getObjectFactory() {
  return *objectFactory;
}

void ObjectFactoryService::setObjectFactory(shared_ptr<ObjectFactory> o) {
  objectFactory = o;
}
