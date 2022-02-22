/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.20: Write a program to copy elements from a list<int> into
two deques. The even-valued elements should go into one deque and the
odd ones into the other.

https://github.com/Mooophy/Cpp-Primer/blob/master/ch09/ex9_20.cpp
https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.20.cpp

*/

#include <deque>
#include <iostream>
#include <list>
using std::cin;
using std::cout;
using std::deque;
using std::endl;
using std::list;

int main() {
  list<int> lst{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  deque<int> odd, even;
  for (auto i : lst)
    (i & 0x1 ? odd : even).push_back(i);  // TODO: What is this?

  for (auto i : odd) cout << i << " ";
  cout << endl;
  for (auto i : even) cout << i << " ";
  cout << endl;

  return 0;
}