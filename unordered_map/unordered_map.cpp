#include <iostream>
#include <unordered_map>

int main() {

  using NamesList = std::unordered_map<int, std::string>;
  NamesList myMap = {{1, "sebastian"}, {2, "tleye"}, {3, "yamil"}};

  myMap.emplace(4, "pepito");

  myMap[1] = "hello world";

  std::cout << myMap.at(3) << std::endl;

  if (myMap.contains(2)) {
    std::cout << "Key 2 is present in the map." << std::endl;
  } else {
    std::cout << "Key 2 is not present in the map." << std::endl;
  }

  for (const auto &[key, value] : myMap) {
    std::cout << "key :" << key << ", value: " << value << std::endl;
  }

  return 0;
}