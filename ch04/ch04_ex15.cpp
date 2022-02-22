/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.15: The following assignment is illegal. Why? How would you
correct it?
double dval; int ival; int *pi;
dval = ival = pi = 0;

*/

#include <iostream>

int main() {
  double dval;
  int ival;
  int *pi;
  // dval = ival = pi = 0;
  // the type of `pi` is `int *` which cannot be converted to `int`
  dval = ival = 0;
  pi = 0;

  return 0;
}