/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.38: Describe the differences in type deduction between
decltype and auto. Give an example of an expression where auto and
decltype will deduce the same type and an example where they will deduce
differing types.

Answer:
auto will ignore the top-level const qualifier and reference.
decltype will include top-level const and reference.

Same type

int i;
auto a1 = i;     // int
decltype(i) d1;  // int

Different type

int i, &j = i;
auto a2 = j;     // int
decltype(j) d2;  // int &

const int i;
auto a3 = i;          // int
decltype(i) d3 = 42;  // const int

*/

#include <iostream>

int main() {
  //

  return 0;
}