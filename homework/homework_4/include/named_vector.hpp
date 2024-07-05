#ifndef NAMED_VECTOR_HPP
#define NAMED_VECTOR_HPP

#include <stddef.h>
#include <string>
#include <vector>

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
  std::string name_;
};

// Implementation of named_vector

template <typename T>
named_vector<T>::named_vector(const std::string &name) : name_(name) {}

template <typename T>
named_vector<T>::named_vector(const std::string &name,
                              const std::vector<T> &std_vector)
    : name_(name), v_(std_vector) {}

template <typename T> std::vector<T> named_vector<T>::vector() const {
  return v_;
}

template <typename T> std::string named_vector<T>::name() const {
  return name_;
}

template <typename T> int named_vector<T>::size() const {
  return this->vector().size() + this->name().size();
}

template <typename T> bool named_vector<T>::empty() const {
  return this->vector().empty() || this->name().empty();
}

template <typename T> void named_vector<T>::resize(int size) {
  this->vector().resize(size);
}

template <typename T> int named_vector<T>::capacity() {
  return this->vector().capacity();
}

template <typename T> void named_vector<T>::reserve(size_t n) {
  return this->vector().reserve(n);
}

// Implement the copy assignment operator outside the class declaration
template <typename T>
ipb::named_vector<T> &
ipb::named_vector<T>::operator=(const named_vector<T> &other) {
  if (this == &other)
    return *this;
  v_ = other.v_;
  name_ = other.name_; // Corrected assignment
  return *this;
}

} // namespace ipb

#endif // NAMED_VECTOR_HPP
