#include "ipb_algorithm.hpp"
#include "named_vector.hpp"
#include <iostream>
#include <vector>

using int_vector = ipb::named_vector<int>;

int main() {
  int_vector named_vector{"name", {1, 2, 3, 4}};
  std::cout << std::boolalpha << named_vector.empty() << std::endl;
  std::cout << std::boolalpha << named_vector.name().empty() << std::endl;

  const int k = -100;
  ipb::fill(named_vector, k);
}
