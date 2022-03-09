/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Exercise 1.5:
We wrote the output in one large statement.
Rewrite the program to use a separate statement
to print each operand.
******************************************************************************/

#include <iostream>  // header

int main() {
  std::cout << "Enter two numbers:" << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << "The sum of ";
  std::cout << v1;
  std::cout << " and ";
  std::cout << v2;
  std::cout << " is ";
  std::cout << v1 * v2;
  std::cout << std::endl;

  return 0;
}