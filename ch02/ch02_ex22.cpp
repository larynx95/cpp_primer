/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.22: Assuming p is a pointer to int, explain the following code:
if (p) // ...
if (*p) // ...

Answer:
if (p) means if the pointer p is not null.
if (*p) means if the object pointed by the pointer is not false
   (which means the object is not null or zero etc.).

*/

#include <iostream>

int main() {
  //

  return 0;
}