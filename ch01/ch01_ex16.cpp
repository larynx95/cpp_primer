/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Exercise 1.16: Write your own version of a program that prints the sum of
a set of integers read from cin.

How to read unknown number of inputs?
https://stackoverflow.com/questions/50608176/how-to-read-unknown-number-of-inputs
Ctrl+Z
******************************************************************************/

#include <iostream>

int main() {
  int sum = 0;
  for (int value = 0; std::cin >> value;) sum += value;
  std::cout << sum << std::endl;

  return 0;
}
