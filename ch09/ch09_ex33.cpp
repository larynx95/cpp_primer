/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.33: In the final example in this section what would happen if we
did not assign the result of insert to begin? Write a program that omits
this assignment to see if your expectation was correct.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.33.cpp

*/

#include <vector>
using std::vector;

int main() {
  vector<int> v{1, 2, 3, 4, 5};

  auto begin = v.begin();
  while (begin != v.end()) {
    ++begin;
    begin = v.insert(begin, 42);
    // v.insert(begin, 42);
    // Iterator `begin` will become invalid after insert, thus if we don't
    // update the iterator, any usage of this iterator will have undefined
    // behaviours.
    ++begin;
  }

  return 0;
}