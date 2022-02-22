/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.42: Write a program to copy a vector of ints into an array of
ints.

******************************************************************************/

#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> iv = {1, 2, 3, 4, 5, 6, 7, 8};
  int ia[10];
  int *bg = ia;
  int *ed = ia + iv.size();
  for (const auto &i : iv) *bg++ = i;

  for (bg = ia; bg != ed; ++bg) std::cout << *bg << ' ';
  std::cout << std::endl;

  return 0;
}