/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.20: Read a set of integers into a vector. Print the sum of each
pair of adjacent elements. Change your program so that it prints the sum of
the first and last elements, followed by the sum of the second and second-to-
last, and so on.

******************************************************************************/

#include <iostream>
#include <vector>

void sum_adjacent(const std::vector<int> &v) {
  if (v.size() < 2) return;
  for (decltype(v.size()) i = 0; i < v.size() - 1; ++i)
    std::cout << v[i] + v[i + 1] << '\t';
  std::cout << std::endl;
}

void sum_symmetric(const std::vector<int> &v) {
  // If the vector has odd size, element in the middle will add to itself.
  auto mid = (v.size() + 1) / 2;
  for (decltype(mid) i = 0; i != mid; ++i)
    std::cout << v[i] + v[v.size() - 1 - i] << '\t';
  std::cout << std::endl;
}

int main() {
  std::vector<int> iv;
  int i;
  while (std::cin >> i) iv.push_back(i);

  sum_adjacent(iv);
  sum_symmetric(iv);

  return 0;
}