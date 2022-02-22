/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.12: Assuming i, j, and k are all ints, explain what i != j <
k means.

Answer:
The expression i != j < k is the same with i != (j < k).

First, j < k is evaluated and the result is a bool(either true or false).

Second, i != true or i != false is evaluated. Since i is an int, the bool will
be converted to int, which means i != 1 or i != 0 is evaluated.
*/

#include <iostream>

int main() {
  //
  return 0;
}