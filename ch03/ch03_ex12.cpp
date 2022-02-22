/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.12: Which, if any, of the following vector definitions are in
error? For those that are legal, explain what the definition does. For those
that are not legal, explain why they are illegal.
(a) vector<vector<int>> ivec;
(b) vector<string> svec = ivec;
(c) vector<string> svec(10, "null");

******************************************************************************/

#include <cctype>
#include <ostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::vector<int>> ivec;
  // OK, a vector of vector of int, similar to 2-d int array
  // std::vector<std::string> svec = ivec;
  // Error: the type of `svec` and `ivec` doesn't match
  std::vector<std::string> svec2(10, "null");
  // OK, a vector of ten strings whose value are all "null"

  return 0;
}