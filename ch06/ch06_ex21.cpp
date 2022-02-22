/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.21: Write a function that takes an int and a pointer to an int
and returns the larger of the int value or the value to which the pointer
points. What type should you use for the pointer?

*/

#include <iostream>

int largerInt(int a, int *pb) { return a > *pb ? a : *pb; }

int main() {
  //
  return 0;
}