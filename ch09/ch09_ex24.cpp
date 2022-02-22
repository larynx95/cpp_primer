/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.24: Write a program that fetches the first element in a vector
using at, the subscript operator, front, and begin. Test your program on
an empty vector.

*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vi;

  // All of them will cause program terminate
  // int i1 = vi.at(0);
  // int i2 = vi[0];
  // int i3 = vi.front();
  // int i4 = *vi.begin();

  // std::cout << i1 << " " << i2 << " " << i3 << " " << i4 << std::endl;

  return 0;
}