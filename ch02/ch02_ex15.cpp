/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.15: Which of the following definitions, if any, are invalid? Why?
(a) int ival = 1.01;
(b) int &rval1 = 1.01;
(c) int &rval2 = ival;
(d) int &rval3;

*/

#include <iostream>

int main() {
  int ival = 1.01;  // OK
  // int &rval1 = 1.01;  // Error: initializer must be `int` object
  int &rval2 = ival;  // OK
  // int &rval3;  // Error: a reference must be initialized when defined

  return 0;
}