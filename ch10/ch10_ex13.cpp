/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.13: The library defines an algorithm named partition that
takes a predicate and partitions the container so that values for which the
predicate is true appear in the first part and those for which the predicate is
false appear in the second part. The algorithm returns an iterator just past
the last element for which the predicate returned true. Write a function that
takes a string and returns a bool indicating whether the string has five
characters or more. Use that function to partition words. Print the elements
that have five or more characters.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.13.cpp

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool fiveOrMore(const std::string &s) { return s.size() >= 5; }

int main() {
  std::vector<std::string> words{"the",  "quick", "red",  "fox", "jumps",
                                 "over", "the",   "slow", "red", "turtle"};
  auto end_part = partition(words.begin(), words.end(), fiveOrMore);
  for (const auto &word : words) std::cout << word << ' ';
  std::cout << '\n';

  // print first partition
  for (auto wi = words.begin(); wi != end_part; ++wi) std::cout << *wi << ' ';
  std::cout << '\n';

  // print second partition
  for (auto wi = end_part; wi != words.end(); ++wi) std::cout << *wi << ' ';
  std::cout << '\n';

  return 0;
}