#ifndef HEADER_COMPONENT_STORAGE_SERVICE
#define HEADER_COMPONENT_STORAGE_SERVICE
#include <memory>

#include "ComponentStorage.hpp"
using namespace std;

namespace zombone_engine {

class ComponentStorageService {
 public:
  static ComponentStorage &getComponentStorage();
  static void setComponentStorage(shared_ptr<ComponentStorage> cs);

 private:
  static shared_ptr<ComponentStorage> componentStorage;
};

}  // namespace zombone_engine

#endif
