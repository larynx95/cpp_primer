/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.9: Explain the behavior of the condition in the following if:

const char *cp = "Hello World";
if (cp && *cp)

Answer
The condition cp && *cp means if cp is not a null pointer and the object pointed
by cp is not null, 0 or can be converted to false.

*/

#include <iostream>
#include <limits>

int main() {
  //

  return 0;
}