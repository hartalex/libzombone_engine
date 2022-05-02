#ifndef HEADER_OBJECT_FACTORY_SERVICE
#define HEADER_OBJECT_FACTORY_SERVICE
#include <memory>

#include "ObjectFactory.hpp"
using namespace std;

class ObjectFactoryService {
 public:
  static ObjectFactory &getObjectFactory();
  static void setObjectFactory(shared_ptr<ObjectFactory> o);

 private:
  static shared_ptr<ObjectFactory> objectFactory;
};
#endif
