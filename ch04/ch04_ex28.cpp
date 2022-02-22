/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.28: Write a program to print the size of each of the built-in
types.

*/

#include <iostream>

int main() {
  std::cout << "char        " << sizeof(char) << std::endl;         // 1
  std::cout << "wchar_t     " << sizeof(wchar_t) << std::endl;      // 2
  std::cout << "char16_t    " << sizeof(char16_t) << std::endl;     // 2
  std::cout << "char32_t    " << sizeof(char32_t) << std::endl;     // 4
  std::cout << "short       " << sizeof(short) << std::endl;        // 2
  std::cout << "int         " << sizeof(int) << std::endl;          // 4
  std::cout << "long        " << sizeof(long) << std::endl;         // 8
  std::cout << "long long   " << sizeof(long long) << std::endl;    // 8
  std::cout << "float       " << sizeof(float) << std::endl;        // 4
  std::cout << "double      " << sizeof(double) << std::endl;       // 8
  std::cout << "long double " << sizeof(long double) << std::endl;  // 16

  return 0;
}