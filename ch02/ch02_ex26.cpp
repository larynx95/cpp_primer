/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.26: Which of the following are legal? For those that are illegal,
explain why.
(a) const int buf;
(b) int cnt = 0;
(c) const int sz = cnt;
(d) ++cnt; ++sz;

*/

#include <iostream>

int main() {
  // const int buf;    // Error: must be initialized
  int cnt = 0;         // OK
  const int sz = cnt;  // OK
  ++cnt;               // OK
  //++sz;              // Error: cannot change the value of a const variable

  return 0;
}