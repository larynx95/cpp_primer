/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.27: What is the result of each of these expressions?
unsigned long ul1 = 3, ul2 = 7;
(a) ul1 & ul2
(b) ul1 | ul2
(c) ul1 && ul2
(d) ul1 || ul2

*/

#include <iostream>

int main() {
  unsigned long ul1 = 3, ul2 = 7;

  std::cout << (ul1 & ul2) << std::endl;  // 3
  std::cout << (ul1 | ul2) << std::endl;  // 7
  std::cout << (ul1 && ul2) << std::endl;  // 1, means true
  std::cout << (ul1 || ul2) << std::endl;  // 1, means true

  return 0;
}