namespace ipb {

// Constructor definitions
template <typename T> ExampleClass<T>::ExampleClass() : count(0) {}

template <typename T>
ExampleClass<T>::ExampleClass(int initialValue) : count(initialValue) {}

// Destructor definition
template <typename T> ExampleClass<T>::~ExampleClass() {}

// Member function definition
template <typename T>
void ExampleClass<T>::printMessage(const std::string &message) {
  std::cout << "Message: " << message << std::endl;
}

} // namespace ipb
