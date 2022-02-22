/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.23: Write a program to create a vector with ten int elements.
Using an iterator, assign each element a value that is twice its current value.
Test your program by printing the vector.

******************************************************************************/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> iv(10);
  for (int i = 0; i != 10; ++i) std::cin >> iv[i];
  for (auto it = iv.begin(); it != iv.end(); ++it) *it *= 2;
  for (const auto& elem : iv) std::cout << elem << " ";
  std::cout << std::endl;

  return 0;
}