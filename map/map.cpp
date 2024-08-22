#include <iostream>
#include <map>

//Added a comment for testing purposes

int main() {

  using NamesList = std::map<int, std::string>;
  NamesList myMap = {{1, "sebastian"}, {2, "tleye"}, {3, "yamil"}};

  myMap.emplace(4, "pepito");

  myMap[1] = "hello world";

  std::cout << myMap.at(3) << std::endl;

  if (myMap.contains(2)) {
    std::cout << "Key 2 is present in the map." << std::endl;
  } else {
    std::cout << "Key 2 is not present in the map." << std::endl;
  }

  for (const auto &pair : myMap) {
    std::cout << "key :" << pair.first << ", value: " << pair.second
              << std::endl;
  }

  return 0;
}
