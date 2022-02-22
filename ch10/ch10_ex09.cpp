/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.9: Implement your own version of elimDups. Test your
program by printing the vector after you read the input, after the call to
unique, and after the call to erase.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.09.cpp

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> &elimDups(std::vector<std::string> &words) {
  sort(words.begin(), words.end());
  auto end_unique = unique(words.begin(), words.end());
  words.erase(end_unique, words.end());
  return words;
}

int main() {
  std::vector<std::string> words{"the",  "quick", "red",  "fox", "jumps",
                                 "over", "the",   "slow", "red", "turtle"};
  elimDups(words);
  for (const auto &word : words) std::cout << word << ' ';
  std::cout << '\n';

  return 0;
}