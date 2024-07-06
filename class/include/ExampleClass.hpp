#ifndef EXAMPLECLASS_HPP
#define EXAMPLECLASS_HPP

#include <iostream>
#include <string>
#include <vector>

namespace ipb {

template <typename T> class ExampleClass {
public:
  // Constructors
  ExampleClass();
  explicit ExampleClass(int initialValue);

  // Destructor
  ~ExampleClass();

  // Member function declarations
  void printMessage(const std::string &message);

private:
  int count;
  std::vector<T> v_;
};

} // namespace ipb

#include "../src/ExampleClass.tpp" // Include the implementation file here

#endif // EXAMPLECLASS_HPP
