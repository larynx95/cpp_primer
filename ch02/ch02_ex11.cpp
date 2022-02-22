/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.11: Explain whether each of the following is a declaration or a
definition:
(a) extern int ix = 1024;
(b) int iy;
(c) extern int iz;

What is the difference between a definition and a declaration?
https://stackoverflow.com/questions/1410563/what-is-the-difference-between-a-definition-and-a-declaration
*/

#include <iostream>

extern int ix = 1024;  // Definition
int iy;                // Definition
extern int iz;         // Declaration, not definition

int main() {
  // extern int ix2 = 1024;  // Error
  int iy2;         // Definition
  extern int iz2;  // Declaration

  return 0;
}