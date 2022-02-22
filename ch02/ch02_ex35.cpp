/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.35: Determine the types deduced in each of the following
definitions. Once you’ve figured out the types, write a program to see
whether you were correct.

const int i = 42;
auto j = i;
const auto &k = i;
auto *p = &i;
const auto j2 = i, &k2 = i;

*/

#include <iostream>

int main() {
  const int i = 42;            // const int
  auto j = 1;                  // int
  const auto &k = i;           // const int &
  auto *p = &i;                // const int *
  const auto j2 = i, &k2 = i;  // const int, const int &

  return 0;
}