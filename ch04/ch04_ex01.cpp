/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.1: What is the value returned by 5 + 10 * 20/2?

*/

#include <iostream>

int main() {
  std::cout << (5 + 10 * 20 / 2) << std::endl;  // 105
  return 0;
}