/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Exercise 1.11:
Write a program that prompts the user for two integers.
Print each number in the range specified by those two integers.
******************************************************************************/

#include <iostream>

int main() {
  int small = 0, big = 0;
  std::cout << "please input two integers:";
  std::cin >> small >> big;

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