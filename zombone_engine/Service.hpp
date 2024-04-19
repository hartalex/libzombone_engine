#ifndef HEADER_SERVICE
#define HEADER_SERVICE
#include <cstddef>
#include <memory>
#include <stdexcept>

using namespace std;

namespace zombone_engine {

template <class T>
class Service {
 public:
  static T &getValue() {
    if (value == NULL) {
      throw logic_error("Value is not yet initialized");
    }
    return *value;
  };
  static void setValue(shared_ptr<T> v) { value = v; }

 private:
  static shared_ptr<T> value;
};

}  // namespace zombone_engine

#endif
