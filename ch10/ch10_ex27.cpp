/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.27: In addition to unique (§ 10.2.3, p. 384), the library
defines function named unique_copy that takes a third iterator denoting a
destination into which to copy the unique elements. Write a program that
uses unique_copy to copy the unique elements from a vector into an
initially empty list.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.27.cpp

*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> vWords{"blue", "red", "pink", "brown",  "black",
                                  "pink", "red", "blue", "yellow", "white"};
  std::list<std::string> lstWords;
  std::sort(vWords.begin(), vWords.end());  // vector must be sorted
  std::unique_copy(vWords.cbegin(), vWords.cend(), back_inserter(lstWords));
  for (const auto &word : lstWords) std::cout << ' ' << word;
  std::cout << std::endl;
  return 0;
}