/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.6: Use a range for to change all the characters in a string to
X.

******************************************************************************/

#include <iostream>
#include <string>

int main() {
  std::string s;
  if (std::cin >> s) {
    for (auto &c : s)  // `c` is `char &`, so can modify original string
      c = 'X';
  }
  std::cout << s << std::endl;

  return 0;
}