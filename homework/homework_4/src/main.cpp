// #include "ipb_algorithm.hpp"
#include "named_vector.hpp"
#include <vector>

// using int_vector = ipb::named_vector<int>;

int main() {
  // ipb::named_vector<int> myNamedVector("Sebastian", std::vector<int>(5, 0));
  // int_vector v{"name", {1, 2, 3, 4}};
  // std::vector<int> myVector{1, 2, 3, 4};
  std::string name = "Sebastian";
  // int_vector v(name, myVector);
  // int_vector v{name};
  // int_vector v(name);
  ipb::named_vector<int> v(name);
}