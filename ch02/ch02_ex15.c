/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.15: Which of the following definitions, if any, are invalid? Why?
TODO: in C language
What exactly is the difference between “pass by reference” in C and in C++?
https://stackoverflow.com/questions/13654138/what-exactly-is-the-difference-between-pass-by-reference-in-c-and-in-c
(a) int ival = 1.01;
(b) int &rval1 = 1.01;
(c) int &rval2 = ival;
(d) int &rval3;

*/

#include <stdio.h>

int main() {
  int ival = 1.01;
  // int &rval1 = 1.01;
  // int &rval2 = ival;
  // int &rval3;

  return 0;
}