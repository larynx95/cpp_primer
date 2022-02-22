/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.10: Write a program that reads a string of characters including
punctuation and writes what was read but with the punctuation removed.

******************************************************************************/

#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cin >> s;
  for (const auto &c : s)
    if (!ispunct(c)) std::cout << c;
  std::cout << std::endl;

  return 0;
}