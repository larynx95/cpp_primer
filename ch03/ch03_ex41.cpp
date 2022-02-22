/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.41: Write a program to initialize a vector from an array of
ints.

******************************************************************************/

#include <iostream>
#include <iterator>
#include <vector>

int main() {
  int ia[] = {1, 2, 3, 4, 5, 6, 7, 8};
  std::vector<int> iv(std::begin(ia), std::end(ia));
  for (const auto &i : iv) std::cout << i << ' ';
  std::cout << std::endl;

  return 0;
}