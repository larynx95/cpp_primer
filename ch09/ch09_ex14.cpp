/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.14: Write a program to assign the elements from a list of
char* pointers to C-style character strings to a vector of strings.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.14.cpp

*/

#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
  std::list<char *> lc{"aaa", "bbb", "ccc"};
  std::vector<std::string> vs;
  vs.assign(lc.begin(), lc.end());
  std::cout << vs[0] << std::endl;

  return 0;
}