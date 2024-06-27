#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

// Define the Print function
template <typename Container> void Print(const Container &container) {
  for (const auto &element : container) {
    std::cout << element << ' ';
  }
  std::cout << std::endl;
}

int main() {

  //----- sort -----
  std::array<int, 10> s = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

  std::cout << "Before sorting: ";
  Print(s);

  std::sort(s.begin(), s.end());
  std::cout << "After sorting: ";
  Print(s);

  //----- find -----

  const int n1 = 3;
  std::vector<int> v = {0, 1, 2, 3, 4};

  auto result1 = std::find(v.begin(), v.end(), n1);

  if (result1 != std::end(v)) {
    std::cout << "v contains: " << n1 << std::endl;
  } else {
    std::cout << "v does not contain: " << n1 << std::endl;
  }

  //----- fill -----

  std::vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::fill(v1.begin(), v1.end(), -1);
  Print(v1);

  //----- for_each -----

  std::vector<int> nums = {3, 4, 2, 8, 15, 267};
  // lambda expression
  auto print = [](const int &n) { std::cout << " " << n; };

  std::cout << "Numbers:";
  std::for_each(nums.cbegin(), nums.cend(), print);
  std::cout << std::endl;

  return 0;
}