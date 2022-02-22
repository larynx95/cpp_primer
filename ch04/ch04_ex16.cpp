/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.16: Although the following are legal, they probably do not
behave as the programmer expects. Why? Rewrite the expressions as you
think they should be.
(a) if (p = getPtr() != 0)
(b) if (i = 1024)

Answer:
if (p = getPtr() != 0) is the same with if (p = (getPtr() != 0)) and should be
if ((p = getPtr()) != 0).

if (i = 1024) may be if (i == 1024).
*/

#include <iostream>

int main() {
  //

  return 0;
}