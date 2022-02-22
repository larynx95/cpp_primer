/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.13: What are the values of i and d after each assignment?
int i; double d;
(a) d = i = 3.5;
(b) i = d = 3.5;

*/

#include <iostream>

int main() {
  int i;
  double d;
  d = i = 3.5;
  std::cout << d << ' ' << i << std::endl;  // 3 3
  i = d = 3.5;
  std::cout << d << ' ' << i << std::endl;  // 3.5 3

  return 0;
}