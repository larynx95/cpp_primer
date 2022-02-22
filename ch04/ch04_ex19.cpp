/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.19: Given that ptr points to an int, that vec is a
vector<int>, and that ival is an int, explain the behavior of each of
these expressions. Which, if any, are likely to be incorrect? Why? How might
each be corrected?
(a) ptr != 0 && *ptr++
(b) ival++ && ival
(c) vec[ival++] <= vec[ival]

Answer:
(a) ptr != 0 && *ptr++

The expression means if ptr is not null pointer, then point to whatever next in
memory and return a copy of the value of the original int variable. Since we
don't know what next in memory is, it will be an error if we dereference ptr
after the expression. The expression may be:

ptr != 0 && (*ptr)++

(b) ival++ && ival

The expression first increases the value of ival and return a copy of the
original value, then if the original value is nonzero, the right hand operand
ival(the incremented one) is evaluated, if it is also nonzero, the expression is
true, else it is `false.

(c) vec[ival++] <= vec[ival]

The order of evaluation of <= operator's operands is undefined. The expression
should be:

++ival, vec[ival] <= vec[ival + 1]

*/

#include <iostream>

int main() {
  //

  return 0;
}