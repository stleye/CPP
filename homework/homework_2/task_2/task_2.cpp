#include <iomanip>
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

  int num1, num2 = 0;
  std::string str1, str2 = "";
  std::string ext1, ext2;

  filename1 >> str1 >> ext1;
  filename2 >> str2 >> ext2;
  filename1 >> num1 >> ext1;
  filename2 >> num2 >> ext2;

  std::cout << str1 << std::endl;
  std::cout << str2 << std::endl;
  std::cout << num1 << std::endl;
  std::cout << num2 << std::endl;

  //   if (num1 == "0" || num2 == "0") {
  //     return EXIT_FAILURE;
  //   }

  //   if (ext1 == ext2) {
  //     if (ext1 == ".txt") {
  //       std::cout << "The mean is: " << (num1 + num2) / 2 << std::endl;
  //     } else if (ext1 == ".png") {
  //       std::cout << "The sum is: " << (num1 + num2) << std::endl;
  //     }
  //   } else if (ext1 == ".txt" && ext2 == ".png") {
  //     std::cout << "The modulo division is: " << (num1 % num2) << std::endl;
  //   } else {
  //     std::cerr << "Types do not match expectations" << std::endl;
  //   }

  return EXIT_SUCCESS;
}
