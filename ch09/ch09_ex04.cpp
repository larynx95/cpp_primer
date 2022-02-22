/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.4: Write a function that takes a pair of iterators to a
vector<int> and an int value. Look for that value in the range and return
a bool indicating whether it was found.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.4.cpp
https://github.com/Mooophy/Cpp-Primer/tree/master/ch09

*/

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool contains(vector<int>::const_iterator first,
              vector<int>::const_iterator last, int value) {
  for (; first != last; ++first)
    if (*first == value) return true;
  return false;
}

int main() {
  vector<int> vi = {1, 2, 3, 4, 5, 6, 7};
  if (contains(vi.begin(), vi.end(), 5)) printf("Yes, contains 5");

  return 0;
}