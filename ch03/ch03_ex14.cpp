/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.14: Write a program to read a sequence of ints from cin and
store those values in a vector.

push_back()
https://en.cppreference.com/w/cpp/container/vector/push_back

******************************************************************************/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> iv;
  int i;
  while (std::cin >> i) iv.push_back(i);
  for (const auto& k : iv) std::cout << k << " ";
  std::cout << std::endl;

  return 0;
}