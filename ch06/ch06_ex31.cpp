/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.31: When is it valid to return a reference? A reference to
const?

Answer:
When the object is not a local object, then that's fine to return a reference to
it.

When we don't want the reference returned from a function to be an lvalue, we
should use a reference to const as the return type instead.

*/

#include <iostream>

int main() {
  //
  return 0;
}