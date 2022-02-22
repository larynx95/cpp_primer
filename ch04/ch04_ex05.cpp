/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.5: Determine the result of the following expressions.
(a) -30 * 3 + 21 / 5
(b) -30 + 3 * 21 / 5
(c) 30 / 3 * 21 % 5
(d) -30 / 3 * 21 % 4

*/

#include <iostream>

int main() {
  std::cout << -30 * 3 + 21 / 5 << std::endl;  // -86
  std::cout << -30 + 3 * 21 / 5 << std::endl;  // -18
  std::cout << 30 / 3 * 21 % 5 << std::endl;   // 0
  std::cout << -30 / 3 * 21 % 4 << std::endl;  // -2

  return 0;
}