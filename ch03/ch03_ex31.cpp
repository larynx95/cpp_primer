/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.31: Write a program to define an array of ten ints. Give each
element the same value as its position in the array.

******************************************************************************/

#include <array>
#include <ostream>
#include <string>
#include <vector>

int main() {
  int ia[10];
  for (size_t i = 0; i != 10; ++i) ia[i] = i;

  // To get the size of an array one could use
  //     sz = sizeof(ia) / sizeof(*ia)
  // However, this will not work for some situations like dynamically allocated
  // array, pointer array, array in function parameter etc.

  return 0;
}