/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.2:
Repeat the previous program, but read values into a list of strings.

<algorithm> :: count
https://en.cppreference.com/w/cpp/algorithm

https://github.com/Mooophy/Cpp-Primer/blob/master/ch10/ex10_01_02.cpp

*/

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
  // 10.1
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 6, 6, 2};
  std::cout << "ex 10.01: " << std::count(v.cbegin(), v.cend(), 6) << std::endl;

  // 10.2
  std::list<std::string> l = {"aa", "aaa", "aa", "cc"};
  std::cout << "ex 10.02: " << std::count(l.cbegin(), l.cend(), "aa")
            << std::endl;

  return 0;
}