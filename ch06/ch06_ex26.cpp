/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.26: Write a program that accepts the options presented in this
section. Print the values of the arguments passed to main.

*/

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::cout << "All " << argc << " argument" << (argc > 1 ? "s are:" : " is:")
            << std::endl;
  for (int i = 0; i < argc; ++i) std::cout << i << "\t" << argv[i] << std::endl;

  return 0;
}