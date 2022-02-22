/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.26: In the binary search program on page 112, why did we write
mid = beg + (end - beg) / 2; instead of mid = (beg + end)
/2;?

Answer:
First, there is no operator + for two iterators.
Second, for arithmetic types,
using mid = (beg + end) / 2 may lead to overflow.

******************************************************************************/

#include <iostream>
#include <vector>

int main() {
  //

  return 0;
}