/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.35: Now print the elements in reverse order using ordinary
iterators.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.35.cpp

*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for (auto it = ivec.cend() - 1; it >= ivec.begin(); --it)
    std::cout << ' ' << *it;
  std::cout << '\n';
  return 0;
}