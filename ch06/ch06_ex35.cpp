/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.35: In the call to fact, why did we pass val - 1 rather than
val--?

Answer:
The order of evaluation is undefined for the operator *, thus the expression
return factorial(val--) * val make equal to either of the following expressions:

// Version 1
auto tmp = factorial(val) * val;  // evaluate second operand first
--val;
return tmp;

// Version 2
auto tmp = factorial(val);
--val;
return tmp * val;  // evaluate first operand first

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch6/6.35.md

*/

#include <iostream>

int main() {
  //

  return 0;
}