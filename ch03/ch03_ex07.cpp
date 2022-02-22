/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.7: What would happen if you define the loop control variable in
the previous exercise as type char? Predict the results and then change your
program to use a char to see if you were right.

******************************************************************************/

#include <iostream>
#include <string>

int main() {
  std::string s;
  if (std::cin >> s) {
    for (char c : s) c = 'X';  // will not change s
  }
  std::cout << s << std::endl;

  return 0;
}