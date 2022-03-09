/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Exercise 1.15:
Write programs that contain the common errors discussed in
the box on page 16. Familiarize yourself with the messages the compiler
generates.
******************************************************************************/

#include <iostream>

int main() {
  /* ex1.9 */
  int sum = 0;
  for (int i = 50; i <= 100; ++i) sum += i;
  std::cout << "the sum is: " << sum << std::endl;

  /* ex1.10 */
  for (int i = 10; i >= 0; --i) std::cout << i << " ";
  std::cout << std::endl;

  /* ex1.11 */
  int small = 0, big = 0;
  std::cout << "please input two integers:";
  std::cin >> small >> big;

  if (small > big) {
    int tmp = small;
    small = big;
    big = tmp;
  }

  for (int i = small; i <= big; ++i) std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}
