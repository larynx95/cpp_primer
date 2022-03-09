/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Exercise 1.13:
Rewrite the exercises from § 1.4.1 (p. 13)
using for loops.
******************************************************************************/

#include <iostream>

int main() {
  int i, sum;

  sum = 0;
  for (i = 50; i <= 100; i++)  // exercise 1.9
    sum += i;
  std::cout << "sum is " << sum << std::endl;

  for (i = 10; i >= 0; i--)  // exercise 1.10
    std::cout << i << std::endl;
  return 0;
}
