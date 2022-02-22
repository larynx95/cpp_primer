/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.32: Copy the array you defined in the previous exercise into
another array. Rewrite your program to use vectors.

******************************************************************************/

#include <vector>

int main() {
  int ia[10];
  for (size_t i = 0; i != 10; ++i) ia[i] = i;

  int ia2[10];
  for (size_t i = 0; i != 10; ++i) ia2[i] = ia[i];

  std::vector<int> iv;
  for (int i = 0; i != 10; ++i) iv.push_back(i);

  std::vector<int> iv2(iv);

  return 0;
}