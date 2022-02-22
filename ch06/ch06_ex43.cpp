/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.43: Which one of the following declarations and definitions would
you put in a header? In a source file? Explain why.
(a) inline bool eq(const BigInt&, const BigInt&) {...}
(b) void putValues(int *arr, int size);

Answer:
The declarations of both functions should be put in a header. The definition of
function eq should be put in the same header with declaration. The definition of
function putValues may be put in a source file.

*/

#include <iostream>

int main() {
  //

  return 0;
}