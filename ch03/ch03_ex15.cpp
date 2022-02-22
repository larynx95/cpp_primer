/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.15: Repeat the previous program but read strings this time.

******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> sv;
  std::string s;
  while (std::cin >> s) sv.push_back(s);
  for (const auto& k : sv) std::cout << k << " ";
  std::cout << std::endl;

  return 0;
}