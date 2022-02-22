/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.28: Explain the following definitions. Identify any that are illegal.
(a) int i, *const cp;
(b) int *p1, *const p2;
(c) const int ic, &r = ic;
(d) const int *const p3;
(e) const int *p;

*/

#include <iostream>

int main() {
  //(a)
  // int i, *const cp;  // Error: a const pointer must be initialized
  //(b)
  // int *p1, *const p2;  // Error: a const pointer must be initialized
  //(c)
  // const int ic, &r = ic;  // Error: const int `ic` must be initialized
  //(d)
  // const int *const p3;  // Error: a const pointer must be initialized
  //(e)
  const int *p;  // OK

  return 0;
}