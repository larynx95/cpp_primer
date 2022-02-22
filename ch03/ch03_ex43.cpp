/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.43: Write three different versions of a program to print the
elements of ia. One version should use a range for to manage the
iteration, the other two should use an ordinary for loop in one case using
subscripts and in the other using pointers. In all three programs write all the
types directly. That is, do not use a type alias, auto, or decltype to
simplify the code.

******************************************************************************/

#include <iostream>

int main() {
  constexpr size_t c_row = 3;
  constexpr size_t c_col = 4;
  int ia[c_row][c_col] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};

  for (const int(&row)[c_col] : ia) {
    for (const int &col : row) std::cout << col << '\t';
    std::cout << std::endl;
  }

  for (size_t i = 0; i != c_row; ++i) {
    for (size_t j = 0; j != c_col; ++j) std::cout << ia[i][j] << '\t';
    std::cout << std::endl;
  }

  for (int(*pr)[c_col] = ia; pr != ia + c_row; ++pr) {
    for (int *pc = *pr; pc != *pr + c_col; ++pc) std::cout << *pc << '\t';
    std::cout << std::endl;
  }

  return 0;
}