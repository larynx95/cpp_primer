/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.10: Write the condition for a while loop that would read ints
from the standard input and stop when the value read is equal to 42.

*/

#include <iostream>

int main() {
  int i;
  while (std::cin >> i && i != 42) { /* do something */
  }
  return 0;
}