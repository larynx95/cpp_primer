/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.11: Write an expression that tests four values, a, b, c, and d,
and ensures that a is greater than b, which is greater than c, which is
greater than d.

*/

#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  if (a > b && b > c && c > d) { /* do something */
  }
  return 0;
}