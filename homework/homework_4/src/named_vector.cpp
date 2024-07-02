#include "named_vector.hpp"

namespace ipb {

// Constructor
template <typename T>
ipb::NamedVector<T>::NamedVector(const std::string &name) : name_(name) {}

// Member function to return the vector
template <typename T> std::vector<T> ipb::NamedVector<T>::vector() const {
  return v_;
}

// Member function to return the name
template <typename T> std::string ipb::NamedVector<T>::name() const {
  return name_;
}

template <typename T> int ipb::NamedVector<T>::size() const {
  return this->vector().size() + this->name().size();
}

template <typename T> bool ipb::NamedVector<T>::empty() const {
  return this->vector().empty() || this->name().empty();
}

template <typename T> voidipb::NamedVector<T>::resize(int size) {
  this->vector().resize(size);
}

template <typename T> int ipb::NamedVector<T>::capacity() {
  return this->vector().capacity();
}

template <typename T> void ipb::NamedVector<T>::reserve(size_t n) {
  return this->vector().reserve(n);
}

} // namespace ipb