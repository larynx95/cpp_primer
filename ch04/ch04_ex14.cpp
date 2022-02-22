/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.14: Explain what happens in each of the if tests:
if (42 = i) // ...
if (i = 42) // ...

Answer:
if (42 = i) // ... is an error.

if (i = 42) // ... will first assign 42 to i and yield the value of i as the
condition expression of if statement. And because 42 is nonzero, the condition
will be true.

*/

#include <iostream>

int main() {
  //

  return 0;
}