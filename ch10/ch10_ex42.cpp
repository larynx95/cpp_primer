/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.42: Reimplement the program that eliminated duplicate words
that we wrote in § 10.2.3 (p. 383) to use a list instead of a vector.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.42.cpp

*/

#include <iostream>
#include <list>
#include <string>

int main() {
  std::list<std::string> words{"the",  "quick", "red",  "fox", "jumps",
                               "over", "the",   "slow", "red", "turtle"};
  words.sort();
  words.unique();
  for (const auto &elem : words) std::cout << elem << ' ';
  std::cout << std::endl;
  return 0;
}