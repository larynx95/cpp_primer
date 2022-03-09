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


(a) * (vec.begin())
        Rules of evaluation
                precedence: . () are equal, and * is lower than both
                Order of associativity (left to right): . ()
(b) (* (vec.begin()) + 1)
        Rules of evaluation:
                precedence: . () are equal and * + are equal but lower than . ()
                Order of associativity (left to right): . ()
                Order of associativity (right to left): * +
*/

#include <iostream>

int main() {
  //
  return 0;
}