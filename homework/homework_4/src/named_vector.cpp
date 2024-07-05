#include "named_vector.hpp"

namespace ipb {

// Constructor
template <typename T>
named_vector<T>::named_vector(const std::string &name) : name_(name) {}

template <typename T>
named_vector<T>::named_vector(const std::string &name,
                              const std::vector<T> &std_vector)
    : name_(name), v_(std_vector) {}

// Member function to return the vector
template <typename T> std::vector<T> named_vector<T>::vector() const {
  return v_;
}

// Member function to return the name
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

} // namespace ipb