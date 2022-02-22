/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.14: Write a lambda that takes two ints and returns their sum.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.14.cpp

*/

#include <iostream>

int main() {
  auto sum = [](const int &a, const int &b) { return a + b; };
  int x{5}, y{10};
  std::cout << sum(x, y) << '\n';

  return 0;
}