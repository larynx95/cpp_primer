/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.25: Rewrite the grade clustering program from § 3.3.3 (p. 104)
using iterators instead of subscripts.

******************************************************************************/

#include <iostream>
#include <vector>

int main() {
  std::vector<unsigned> scores(11, 0);
  unsigned grade;
  while (std::cin >> grade) ++*(scores.begin() + grade / 10);
  for (const auto& elem : scores) std::cout << elem << ' ';
  std::cout << std::endl;

  return 0;
}