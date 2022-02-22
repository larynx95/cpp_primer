/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.35: Given the following definitions,
char cval; int ival; unsigned int ui;
float fval; double dval;
identify the implicit type conversions, if any, taking place:
(a) cval = 'a' + 3;
(b) fval = ui - ival * 1.0;
(c) dval = ui * fval;
(d) cval = ival + fval + dval;

*/

#include <iostream>

int main() {
  char cval = 0;
  int ival = 0;
  unsigned int ui = 0;
  float fval = 0;
  double dval = 0;

  cval = 'a' + 3;
  // 'a' is promoted to `int`, then added to `3`, then converted to `char`.

  fval = ui - ival * 1.0;
  // `ival` is converted to double, then multiplied by `1.0`. The result is
  // converted to `unsigned int`, then subtracted by `ui`. The result is
  // converted to `float`, then assigned to `fval`.

  dval = ui * fval;
  // Since `float` usually has more bits then `unsigned int`, `ui` is converted
  // to `float`, then multiplied by `fval`. The result is converted to
  // `double`, then assigned to `dval`.

  cval = ival + fval + dval;
  // `ival` is converted to `float`, then added to `fval`. The result is
  // converted to `double`, then added to `dval`. The result is converted to
  // `char`, then assigned to `cval`.

  return 0;
}