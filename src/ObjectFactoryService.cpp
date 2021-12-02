#include "ObjectFactoryService.hpp"

#include <cstddef>

/* #include "DummyObjectFactory.hpp" */
#include "ObjectFactory.hpp"
#include "ObjectFileFactory.hpp"

/* ObjectFactory *ObjectFactoryService::objectFactory = NULL; */

ObjectFactory &ObjectFactoryService::getObjectFactory() {
  /* if (objectFactory == NULL) { */
  /*   objectFactory = new DummyObjectFactory(); */
  /* } */
  return *objectFactory;
}
