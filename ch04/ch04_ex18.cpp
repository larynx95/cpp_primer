/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.18: What would happen if the while loop on page 148 that
prints the elements from a vector used the prefix increment operator?

Answer:
The loop will print all elements except the first one in the vector, and also
try to dereference to one past the last element, which is an error. Also, if
there is no negative value in the vector, the loop will continue to dereference
whatever in memeory until a negative value is found, which is a disaster.
*/

#include <iostream>

int main() {
  //

  return 0;
}