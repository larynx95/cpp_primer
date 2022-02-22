/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.6: Using fill_n, write a program to set a sequence of int
values to 0.

TODO: initializing vector
https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.06.cpp
*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> ivec(10, 1);
  // notice: this vector has its length, not empty
  for (const auto& elem : ivec) std::cout << elem << ' ';
  std::cout << '\n';

  fill_n(ivec.begin(), 10, 0);
  for (const auto& elem : ivec) std::cout << elem << ' ';
  std::cout << '\n';

  return 0;
}