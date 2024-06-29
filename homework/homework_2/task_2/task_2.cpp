#include <iostream>
#include <sstream>
#include <string>

int main(int argc, const char *argv[]) {

  if (argc != 3) {
    std::cerr << "You should pass 2 arguments with format <INT>.<EXT>"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::stringstream filename1(argv[1]);
  std::stringstream filename2(argv[2]);

  std::string ext1, ext2;
  int num1, num2;

  filename1 >> num1 >> ext1;
  filename2 >> num2 >> ext2;

  if (filename1.fail() || filename2.fail()) {
    std::cout << "Invalid filenames" << std::endl;
    return EXIT_FAILURE;
  }

  if (ext1 == ext2) {
    if (ext1 == ".txt") {
      std::cout << (num1 + num2) / 2 << std::endl;
    } else if (ext1 == ".png") {
      std::cout << (num1 + num2) << std::endl;
    }
  } else if (ext1 == ".txt" && ext2 == ".png") {
    std::cout << (num1 % num2) << std::endl;
  } else {
    std::cerr << "Incorrect filename extension" << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
