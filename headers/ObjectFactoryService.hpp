#ifndef HEADER_OBJECT_FACTORY_SERVICE
#define HEADER_OBJECT_FACTORY_SERVICE
#include <memory>

#include "ObjectFactory.hpp"

export class ObjectFactoryService {
 public:
  static ObjectFactory &getObjectFactory();

 private:
  static std::unique_ptr<ObjectFactory> objectFactory;
};
#endif
