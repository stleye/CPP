#ifndef IPB_ALGORITHM_HPP
#define IPB_ALGORITHM_HPP

#include "named_vector.hpp"

namespace ipb {

int accumulate(const named_vector<int> &nv);
int count(const named_vector<int> &nv);
bool all_even(const named_vector<int> &nv);
void clamp(named_vector<int> &nv, int lo, int hi);
void fill(named_vector<int>, int value);
bool find(const named_vector<int>, int value);
void print(const named_vector<int>, int value);
void toupper(const named_vector<int>);
void sort(const named_vector<int>);
void rotate(const named_vector<int>);
void reverse(const named_vector<int>);

} // namespace ipb

#endif // RECTANGLE_HPP