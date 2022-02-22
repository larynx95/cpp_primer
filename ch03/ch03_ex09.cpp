/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.9: What does the following program do? Is it valid? If not, why
not?

string s;
cout << s[0] << endl;

******************************************************************************/

#include <cctype>
#include <iostream>
#include <string>

int main() {
  std::string s;
  std::cout
      << s[0]
      << std::endl;  // The subscript is out of range, result is undefined.

  return 0;
}