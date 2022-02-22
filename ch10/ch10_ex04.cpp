/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.4: Assuming v is a vector<double>, what, if anything, is
wrong with calling accumulate(v.cbegin(), v.cend(), 0)?

*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main() {
  // Exercise 10.3
  std::vector<int> v = {1, 2, 3, 4};
  std::cout << "ex 10.03: " << std::accumulate(v.cbegin(), v.cend(), 0)
            << std::endl;

  // Exercise 10.4
  // type of initial value should be double
  std::vector<double> vd = {1.1, 0.5, 3.3};
  std::cout << "ex 10.04: " << std::accumulate(vd.cbegin(), vd.cend(), 0.0)
            << std::endl;

  return 0;
}