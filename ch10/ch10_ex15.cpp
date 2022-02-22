/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.15: Write a lambda that captures an int from its enclosing
function and takes an int parameter. The lambda should return the sum of
the captured int and the int parameter.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.15.cpp

*/

#include <iostream>

int main() {
  int x{5}, y{10};
  auto sum = [y](const int &x) { return x + y; };
  std::cout << sum(x) << '\n';

  return 0;
}