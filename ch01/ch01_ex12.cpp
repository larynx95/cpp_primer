/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Exercise 1.12:
What does the following for loop do?
What is the final value of sum?

    int sum = 0;
    for (int i = -100; i <= 100; ++i)
    sum += i;

Answer:
- add numbers from -100 to 100, and the result is 0
******************************************************************************/

#include <iostream>

int main() {
  int sum = 0;
  for (int i = -100; i <= 100; ++i) sum += i;
  std::cout << "Sum is " << sum;
  return 0;
}
