/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.4: Write a program to read two strings and report whether the
strings are equal. If not, report which of the two is larger. Now, change
the program to report whether the strings have the same length, and if
not, report which is longer.

******************************************************************************/

#include <iostream>
#include <string>

void check_equal() {
  std::string s1, s2;
  if (std::cin >> s1 >> s2) {
    if (s1 == s2)
      std::cout << "The two strings are equal." << std::endl;
    else if (s1 > s2)
      std::cout << "The first string is larger." << std::endl;
    else
      std::cout << "The second string is larger." << std::endl;
  }
}

void check_length() {
  std::string s1, s2;
  if (std::cin >> s1 >> s2) {
    if (s1.size() == s2.size())
      std::cout << "The two strings have same length." << std::endl;
    else if (s1.size() > s2.size())
      std::cout << "The first string is longer." << std::endl;
    else
      std::cout << "The second string is longer." << std::endl;
  }
}

int main() {
  // check_equal();
  // check_length();

  return 0;
}