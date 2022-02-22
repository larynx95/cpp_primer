/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.6: Write an expression to determine whether an int value is
even or odd.

*/

#include <iostream>

int main() {
  int i;
  std::cin >> i;
  if (i % 2)
    std::cout << i << " is an odd number." << std::endl;
  else
    std::cout << i << " is an even number." << std::endl;

  return 0;
}