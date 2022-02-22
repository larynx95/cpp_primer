/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.27: Write a function that takes an initializer_list<int>
and produces the sum of the elements in the list.

*/

#include <initializer_list>
#include <iostream>

int sumIntList(std::initializer_list<int> il) {
  int sum = 0;
  // `il.begin()` or `il.end()` will return `const int *`
  for (auto &e : il)
    // `e` is `const int &`, since element in `il` are `const int`
    sum += e;
  return sum;
}

int main() {
  std::cout << sumIntList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) << std::endl;

  return 0;
}