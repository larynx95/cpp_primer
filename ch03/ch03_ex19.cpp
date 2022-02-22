/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.19: List three ways to define a vector and give it ten elements,
each with the value 42. Indicate whether there is a preferred way to do so
and why.

******************************************************************************/

#include <vector>
using std::vector;

int main() {
  vector<int> v1(10, 42);
  vector<int> v2{42, 42, 42, 42, 42, 42, 42, 42, 42, 42};
  vector<int> v3;
  for (int i = 0; i != 10; ++i) v3.push_back(42);

  // The way with parentheses is prefered here. It contains less code.

  return 0;
}