#include "zombone_engine/ComponentStorageService.hpp"

#include <cstddef>
#include <stdexcept>

#include "zombone_engine/ComponentStorage.hpp"
using namespace std;

namespace zombone_engine {

shared_ptr<ComponentStorage> ComponentStorageService::componentStorage(nullptr);

ComponentStorage &ComponentStorageService::getComponentStorage() {
  if (componentStorage == NULL) {
    throw logic_error("Component Storage is not yet initialized");
  }
  return *componentStorage;
}

void ComponentStorageService::setComponentStorage(
    shared_ptr<ComponentStorage> cs) {
  componentStorage = cs;
}

}  // namespace zombone_engine
