/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.34: Use reverse_iterators to print a vector in reverse
order.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.34.cpp

*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::ostream_iterator<int> out_iter(std::cout, " ");
  std::copy(ivec.crbegin(), ivec.crend(), out_iter);
  std::cout << std::endl;
  return 0;
}