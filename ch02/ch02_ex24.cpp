/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.24: Why is the initialization of p legal but that of lp illegal?

int i = 42;
void *p = &i;
long *lp = &i;


What is a void pointer in C++? [duplicate]
https://stackoverflow.com/questions/8530080/what-is-a-void-pointer-in-c

What is a void pointer and what is a null pointer?
https://stackoverflow.com/questions/4334831/what-is-a-void-pointer-and-what-is-a-null-pointer
*/

#include <iostream>

int main() {
  int i = 42;
  void *p = &i;  // OK, a `void *` pointer can point to any type
  // long *lp = &i;  // Error, a `long *` pointer can not point to `int *`

  return 0;
}