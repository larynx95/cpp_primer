/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.17: Assuming c1 and c2 are containers, what (if any)
constraints does the following usage place on the types of c1 and c2?
if (c1 < c2)

Answer:
The constraints are:

- the lefthand and righthand operands must have the same container type and
element type.

- the element of the container must support the < operator.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.17.md

*/

#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
  //

  return 0;
}