#include <array>
#include <iostream>
using std::cout;
using std::endl;

int main() {
  std::array<float, 3> data = {10.0F, 100.0F, 1000.0F};

  for (const auto &elem : data) {
    cout << elem << endl;
  }

  cout << std::boolalpha;
  cout << "Array empty: " << data.empty() << endl;
  cout << "Array size : " << data.size() << endl;
}