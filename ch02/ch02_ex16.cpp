/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.16: Which, if any, of the following assignments are invalid? If
they are valid, explain what they do.

*/

#include <iostream>

int main() {
  int i = 0, &r1 = i;
  double d = 0, &r2 = d;

  r2 = 3.14159;  // d = 3.14159
  r2 = r1;       // d = i
  i = r2;        // i = d
  r1 = d;        // i = d

  return 0;
}