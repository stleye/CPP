#include <iostream>
#include <vector>

int main() {

  const int N = 100;

  std::vector<int> vec;
  vec.reserve(N);
  for (int i = 0; i < N; ++i) {
    vec.emplace_back(i);
  }

  std::vector<int> vec2;
  for (int i = 0; i < N; ++i) {
    vec2.emplace_back(i);
  }
}