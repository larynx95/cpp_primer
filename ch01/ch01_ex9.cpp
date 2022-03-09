/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Exercise 1.9:
Write a program that uses a while
to sum the numbers from 50 to 100.
******************************************************************************/

#include <iostream>

int main() {
  int sum{0};
  int i = 50;
  while (i < 101) {
    sum += i;
    i++;
  }
  std::cout << "Sum is " << sum;  // 3825
  return 0;
}
