/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.40: Which, if either, of the following declarations are errors?
Why?
(a) int ff(int a, int b = 0, int c = 0);
(b) char *init(int ht = 24, int wd, char bckgrnd);

Answer:
(a)
int ff(int a, int b = 0, int c = 0);  // OK

(b)
char *init(int ht = 24, int wd, char bckgrnd);
// Error, all the parameters followed `ht` must also have default argument.

*/

#include <iostream>

int main() {
  //
  return 0;
}