/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.21: Explain each of the following definitions. Indicate whether
any are illegal and, if so, why.

int i = 0;
(a) double* dp = &i;
(b) int *ip = i;
(c) int *p = &i;

*/

#include <iostream>

int main() {
  int i = 0;
  // double *dp = &i;  // type mismatch
  // int *ip = i;      // a pointer can only hold address to object
  int *p = &i;

  return 0;
}