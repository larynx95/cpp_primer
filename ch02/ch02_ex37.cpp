/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.37: Assignment is an example of an expression that yields a
reference type. The type is a reference to the type of the left-hand operand.
That is, if i is an int, then the type of the expression i = x is int&. Using
that knowledge, determine the type and value of each variable in this code:

int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;

*/

#include <iostream>

int main() {
  int a = 3, b = 4;
  decltype(a) c = a;  // `c` is `int`
  decltype(a = b) d = a;
  // `d` is `int &` to a, the expression is not evaluated
  std::cout << a << " " << b << " " << c << " " << d << std::endl;  // 3 4 3 3

  return 0;
}