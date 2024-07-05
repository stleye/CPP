#include "ipb_algorithm.hpp"
#include <algorithm>

namespace ipb {

int accumulate(const named_vector<int> &nv) {
  int res = 0;
  for (auto &elem : nv.vector()) {
    res += elem;
  }
  return res;
}

int count(const named_vector<int> &nv) { return nv.vector().size(); }

bool all_even(const named_vector<int> &nv) {
  bool res = true;
  for (auto &elem : nv.vector()) {
    res = res && ((elem % 2) == 0);
  }
  return res;
}

void clamp(named_vector<int> &nv, int lo, int hi) {
  std::vector<int> v;
  for (int i = 0; i < nv.vector().size(); ++i) {
    v.push_back(std::clamp(nv.vector()[i], lo, hi));
  }
  nv = ipb::named_vector<int>(nv.name(), v);
}

void fill(named_vector<int> &nv, int value) {
  for (int i = 0; i < nv.vector().size(); ++i) {
    nv.vector()[i] = value;
  }
}

bool find(const named_vector<int> &nv, int value) {
  for (auto &elem : nv.vector()) {
    if (elem == value) {
      return true;
    }
  }
  return false;
}

void print(const named_vector<int> &nv, int value) {}

void toupper(const named_vector<int> &nv) {}

void sort(const named_vector<int>) {}

void rotate(const named_vector<int>) {}

void reverse(const named_vector<int>) {}

} // namespace ipb