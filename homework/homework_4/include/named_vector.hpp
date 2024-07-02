#ifndef NAMED_VECTOR_HPP
#define NAMED_VECTOR_HPP

#include <stddef.h>
#include <string>
#include <vector>

using namespace std;

namespace ipb {

template <typename T> class NamedVector {
public:
  // Constructor
  NamedVector(const std::string &name);

  // Member functions
  std::vector<T> vector() const;
  std::string name() const;
  int size() const;
  bool empty() const;
  void reserve(size_t n);
  void resize(int size);
  int capacity();

private:
  // Member variables
  std::vector<T> v_;
  const std::string name_;
};
} // namespace ipb

#endif // RECTANGLE_HPP
