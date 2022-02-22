/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.17: What does the following code print?
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;

What are the differences between a pointer variable and a reference variable in
C++?
https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in
*/

#include <iostream>

int main() {
  int i, &ri = i;
  i = 5;
  ri = 10;
  std::cout << i << " " << ri << std::endl;  // 10 10

  return 0;
}