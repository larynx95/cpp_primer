/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.27: Assuming txt_size is a function that takes no arguments
and returns an int value, which of the following definitions are illegal?
Explain why.
unsigned buf_size = 1024;
(a) int ia[buf_size];
(b) int ia[4 * 7 - 14];
(c) int ia[txt_size()];
(d) char st[11] = "fundamental";

Array in C++
- fixed size
- same type
- no auto keyword
- dimension must be a constant expression

******************************************************************************/

#include <iostream>
#include <vector>

int txt_size();

int main() {
  unsigned buf_size = 1024;

  // int ia1[buf_size];            // Error: `buf_size` must be `constexpr`
  int ia2[4 * 7 - 14];  // OK
  // int ia3[txt_size()];          // Error: `txt_size()` must be a `constexpr`
  // function char st[11] = "fundamental";  // Error: the size of string is 12
  // with a trailing '\0'

  return 0;
}