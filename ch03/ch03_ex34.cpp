/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.34: Given that p1 and p2 point to elements in the same array,
what does the following code do? Are there values of p1 or p2 that make
this code illegal?

p1 += p2 - p1;

Answer:
The code move p1 to p2, it is the same with p1 = p2.
Any values are legal as long as both p1 and p2 point to elements in the same
array.
******************************************************************************/

#include <vector>

int main() {
  //

  return 0;
}