/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.33: What would happen if we did not initialize the scores array
in the program on page 116?

Answer:
If the scores array was defined inside a function, then the value of each
element is undefined. If the scores array was defined outside any function, then
the value of each element is 0.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch3/3.33.md

******************************************************************************/

#include <vector>

int main() {
  //

  return 0;
}