/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.39: Write a program to compare two strings. Now write a
program to compare the values of two C-style character strings.

******************************************************************************/

#include <cstring>  // c style string functions
#include <iostream>
#include <string>

int main() {
  std::string s1, s2;
  std::cin >> s1 >> s2;
  if (s1 == s2)
    std::cout << "Two strings are equal." << std::endl;
  else
    std::cout << "Two strings are not equal." << std::endl;

  char cs1[100];
  char cs2[100];
  std::cin >> cs1 >> cs2;
  if (!strcmp(cs1, cs2))
    std::cout << "Two C-style strings are equal." << std::endl;
  else
    std::cout << "Two C-style strings are not equal." << std::endl;

  return 0;
}