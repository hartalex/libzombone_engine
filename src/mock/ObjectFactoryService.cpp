#include "zombone_engine/ObjectFactoryService.hpp"

#include <memory>

#include "zombone_engine/ObjectFactory.hpp"
using namespace std;
namespace zombone_engine {

shared_ptr<ObjectFactory> ObjectFactoryService::objectFactory(nullptr);

ObjectFactory &ObjectFactoryService::getObjectFactory() {
  return *objectFactory;
}

void ObjectFactoryService::setObjectFactory(shared_ptr<ObjectFactory> o) {
  objectFactory = o;
}

}  // namespace zombone_engine
