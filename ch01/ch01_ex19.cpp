/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Exercise 1.19:
Revise the program you wrote for the exercises in § 1.4.1 (p.
13) that printed a range of numbers so that it handles input
in which the first number is smaller than the second.

******************************************************************************/

#include <iostream>

int main() {
  int small = 0, big = 0;
  std::cout << "please input two integers:";
  std::cin >> small >> big;

  // swap
  if (small > big) {
    int tmp = small;
    small = big;
    big = tmp;
  }

  while (small <= big) {
    std::cout << small << " ";
    ++small;
  }
  std::cout << std::endl;

  return 0;
}
