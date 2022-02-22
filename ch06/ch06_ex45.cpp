/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.45: Review the programs you’ve written for the earlier exercises
and decide whether they should be defined as inline. If so, do so. If not,
explain why they should not be inline.

*/

#include <string>

inline bool isShorter(const std::string &s1, const std::string &s2) {
  return s1.size() < s2.size();
}