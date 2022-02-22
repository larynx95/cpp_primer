/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.34: Given the variable definitions in this section, explain what
conversions take place in the following expressions:
(a) if (fval)
(b) dval = fval + ival;
(c) dval + ival * cval;
Remember that you may need to consider the associativity of the operators.

Answer:
(a) fval is converted to bool. (b) ival is converted to float, then added to
fval, finally the result is converted to double. (c) cval is promoted to int,
then multiplied by ival, then the result is converted to double, then added to
dval.

*/

int main() {
  //

  return 0;
}