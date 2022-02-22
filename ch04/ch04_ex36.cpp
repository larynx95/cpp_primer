/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.36: Assuming i is an int and d is a double write the
expression i *= d so that it does integral, rather than floating-point,
multiplication.

*/

#include <iostream>

int main() {
  int i = 0;
  double d = 0;
  i *= static_cast<int>(d);
  return 0;
}