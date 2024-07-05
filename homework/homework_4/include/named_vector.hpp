#ifndef NAMED_VECTOR_HPP
#define NAMED_VECTOR_HPP

#include <stddef.h>
#include <string>
#include <vector>

using namespace std;

namespace ipb {

template <typename T> class named_vector {
public:
  // Constructor
  named_vector() = default;
  named_vector(const std::string &name);
  named_vector(const std::string &name, const std::vector<T> &std_vector);

  // Member functions
  std::vector<T> vector() const;
  std::string name() const;
  int size() const;
  bool empty() const;
  void reserve(size_t n);
  void resize(int size);
  int capacity();

  // Custom copy assignment operator
  named_vector &operator=(const named_vector &other);

private:
  // Member variables
  std::vector<T> v_;
  const std::string name_;
};

} // namespace ipb

#include "../src/named_vector.tpp"

#endif // RECTANGLE_HPP
