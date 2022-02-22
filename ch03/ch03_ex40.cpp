/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.40: Write a program to define two character arrays initialized
from string literals. Now define a third character array to hold the
concatenation of the two arrays. Use strcpy and strcat to copy the two
arrays into the third.

******************************************************************************/

#include <cstring>
#include <iostream>

int main() {
  char s1[] = "Hello";
  char s2[] = "World";
  char s3[11];
  strcpy(s3, s1);
  strcat(s3, s2);
  std::cout << s3 << std::endl;

  return 0;
}