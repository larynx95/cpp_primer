/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Exercise 1.8:
Indicate which, if any, of the following output statements are
legal:

After you’ve predicted what will happen,
test your answers by compiling a program with each of these statements.
Correct any errors you encounter.
******************************************************************************/

#include <iostream>

int main() {
  std::cout << "/*";
  std::cout << "*/";
  // std::cout << /* "*/" */;
  // std::cout << /* "*/" /* "/*" */;
  return 0;
}
