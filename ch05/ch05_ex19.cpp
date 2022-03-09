/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 05. Statements

Exercise 5.19: Write a program that uses a do while loop to repetitively
request two strings from the user and report which string is less than
the other.

*/

#include <iostream>
#include <string>

int main() {
  std::string s1;
  std::string s2;

  do {
    std::cout << "Enter two string to compare length: \n";
    if (std::cin >> s1 >> s2) {  // no output if strings are equal
      if (s1.size() < s2.size())
        std::cout << s1 << '\n';
      else if (s1.size() > s2.size())
        std::cout << s2 << '\n';
    }
  } while (std::cin);

  return 0;
}
