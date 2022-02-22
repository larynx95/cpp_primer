/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.39: Explain the effect of the second declaration in each one of
the following sets of declarations. Indicate which, if any, are illegal.

(a)
int calc(int, int);
int calc(const int, const int);

(b)
int get();
double get();

(c)
int *reset(int *);
double *reset(double *);

Answer:
(a)

int calc(int, int);
int calc(const int, const int);  // Same with first line, top-level `const` are
ignored (b)

int get();
double get();  // Error, differ only on return types
(c)

int *reset(int *);
double *reset(double *);  // OK, define an overloaded function

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch6/6.39.md

*/

#include <iostream>

int main() {
  //
  return 0;
}