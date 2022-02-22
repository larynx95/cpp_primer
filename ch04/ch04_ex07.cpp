/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.7: What does overflow mean? Show three expressions that will
overflow.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch4/4.7.cpp

*/

#include <iostream>
#include <limits>

int main() {
  // Overflow means the value computed from the variables is out of the range
  // of values that the type of the variable can hold.
  //
  // The behaviour of overflow is undefined.

  int a = std::numeric_limits<int>::max();
  int b = a + 1;
  int c = std::numeric_limits<int>::min();
  int d = c - 1;
  int e = a / 2 + 1;
  int f = e * 2;

  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
  std::cout << "d = " << d << std::endl;
  std::cout << "e = " << e << std::endl;
  std::cout << "f = " << f << std::endl;

  return 0;
}