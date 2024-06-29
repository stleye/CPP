#include <cstdlib>
#include <iostream>
#include <random>

void printRandomNumber(int random) {
  std::cout << "The chosen number was: " << random << std::endl;
}

int main() {
  std::random_device rd;
  std::uniform_int_distribution<int> dist(0, 99);
  int random = dist(rd);
  int guess;

  while (true) {
    std::cout << "Guess the number:" << std::endl;
    std::cin >> guess;

    if (std::cin.fail()) {
      std::cerr << "Error encountered, exiting..." << std::endl;
      printRandomNumber(random);
      return EXIT_FAILURE;
    }

    if (guess < 0 || guess > 99) {
      std::cerr << "[WARNING] : Number must be between 0 and 99" << std::endl;
      printRandomNumber(random);
      return EXIT_FAILURE;
    }

    if (guess < random)
      std::cout << "The target is larger" << std::endl;
    else if (guess > random)
      std::cout << "The target is smaller" << std::endl;
    else {
      std::cout << "YOU WON!!" << std::endl;
      printRandomNumber(random);
      return EXIT_SUCCESS;
    }
  }
}