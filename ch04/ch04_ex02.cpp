/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.2: Using Table 4.12 (p. 166), parenthesize the following
expressions to indicate the order in which the operands are grouped:
(a) * vec.begin()
(b) * vec.begin() + 1

Answer:
(a) * vec.begin() ==> * ((vec.begin)())

The order is: member selector, function call, dereference.

(b) * vec.begin() + 1 ==> ( * ((vec.begin)())) + 1

The order is: member selector, function call, dereference, add.

*/

#include <iostream>

int main() {
  //
  return 0;
}