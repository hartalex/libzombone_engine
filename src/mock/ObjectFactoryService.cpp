#include "ObjectFactoryService.hpp"

#include "ObjectFactory.hpp"

ObjectFactory &ObjectFactoryService::getObjectFactory() {
  return *objectFactory;
}
