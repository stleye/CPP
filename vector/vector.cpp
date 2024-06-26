#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

int main() {
  std::vector<int> numbers = {1, 2, 3};
  std::vector<std::string> names = {"Sebastian", "Tleye"};

  names.emplace_back("Yamil");

  cout << "First Name : " << names.front() << endl;
  cout << "Last number: " << numbers.back() << endl;
}