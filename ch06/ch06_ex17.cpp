/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.17: Write a function to determine whether a string contains
any capital letters. Write a function to change a string to all lowercase. Do
the parameters you used in these functions have the same type? If so, why?
If not, why not?

*/

#include <iostream>
#include <string>

bool hasCapital(const std::string &s) {  // Only ASCII
  for (auto &c : s)  // `c` would be `const char &` since `s` is `const`
    if (c >= 'A' && c <= 'Z') return true;
  return false;
}

void toLowerStr(std::string &s) {  // Only ASCII
  for (auto &c : s)
    if (c >= 'A' && c <= 'Z') c -= 'A' - 'a';
}

// The parameters have different type, because in `hasCapital`, we don't need
// to change the string, but in `toLowerStr`, we need to change the string.

int main() {
  std::string str("Hello World!");
  std::cout << hasCapital("Abc") << " " << hasCapital("abc") << " "
            << hasCapital(str) << std::endl;
  std::cout << str << std::endl;
  toLowerStr(str);
  std::cout << str << std::endl;

  return 0;
}