#include <fstream>
#include <iostream>

using namespace std;

int main() {
  int i;
  double a, b;
  string s;

  // Create an input file stream;
  ifstream in("test_cols.in", ios_base::in);

  while (in >> i >> a >> s >> b) {
    cout << i << ", " << a << ", " << s << ", " << b << endl;
  }
}
