/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.21: Write a lambda that captures a local int variable and
decrements that variable until it reaches 0. Once the variable is 0 additional
calls should no longer decrement the variable. The lambda should return a
bool that indicates whether the captured variable is 0.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.21.cpp

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  int x{10};
  auto f = [&x]() -> bool {
    if (x) {
      --x;
      return false;
    } else
      return true;
  };
  while (!f()) std::cout << x << '\n';
  return 0;
}