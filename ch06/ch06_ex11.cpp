/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.11: Write and test your own version of reset that takes a
reference.

*/

#include <iostream>

void resetInt(int &i) { i = 0; }

int main() {
  int a;
  std::cin >> a;
  std::cout << "before reset: " << a << std::endl;
  resetInt(a);
  std::cout << "after reset:  " << a << std::endl;

  return 0;
}