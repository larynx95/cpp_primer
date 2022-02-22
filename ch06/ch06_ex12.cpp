/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.12: Rewrite the program from exercise 6.10 in § 6.2.1 (p. 210)
to use references instead of pointers to swap the value of two ints. Which
version do you think would be easier to use and why?

*/

#include <iostream>

void swapInt(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  swapInt(a, b);
  std::cout << a << " " << b << std::endl;

  // The reference version looks like easier to use, but the user must know
  // from other source that the function will change the value of the argument.

  return 0;
}