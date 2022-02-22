/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.18: Write code to change the value of a pointer. Write code to
change the value to which the pointer points.

*/

#include <iostream>

int main() {
  int i;
  int *ip = &i;

  *ip = 10;
  std::cout << i << " " << *ip << std::endl;  // 10 10
  i = 5;
  std::cout << i << " " << *ip << std::endl;  // 5 5

  return 0;
}