/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.20: What does the following program do?
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;

*/

#include <iostream>

int main() {
  int i = 42;
  int *p1 = &i;
  *p1 = *p1 * *p1;
  std::cout << *p1 << std::endl;

  return 0;
}