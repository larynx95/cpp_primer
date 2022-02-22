/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.9: Explain the following definitions. For those that are illegal,
explain what’s wrong and how to correct it.
(a) std::cin >> int input_value;
(b) int i = { 3.14 };
(c) double salary = wage = 9999.99;
(d) int i = 3.14;

*/

#include <iostream>

int main() {
  // (a)
  // std::cin >> int input_value;  // Error: variable must be defined before
  // using for input
  int input_value;
  std::cin >> input_value;

  // (b)
  // int i = { 3.14 };   // Error: loss information in list initialization
  double d = {3.14};  // OK
  double d2 = {3};    // OK

  // (c)
  // double salary = wage = 9999.99;  // Error
  double salary, wage;
  salary = wage = 9999.99;

  // (d)
  int i2 = 3.14;  // OK, `i2` is 3

  return 0;
}