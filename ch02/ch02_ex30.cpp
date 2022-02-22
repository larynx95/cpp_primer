/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.30: For each of the following declarations indicate whether the
object being declared has top-level or low-level const.

TODO: What is the `low-level` and `top-level` const?

*/

#include <iostream>

int main() {
  int i;
  const int v2 = 0;  // v2 has top-level const
  int v1 = v2;
  int *p1 = &v1, &r1 = v1;
  const int *p2 = &v2, *const p3 = &i, &r2 = v2;
  // p2 has low-level const
  // p3 has both low-level and top-level const
  // r2 has low-level const
  return 0;
}