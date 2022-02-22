/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.13: Assuming T is the name of a type, explain the difference
between a function declared as void f(T) and void f(T&).

Answer:
void f(T) will pass the argument by value, which means in the function f, a copy
of T will be made.

void f(T&) will pass the argument by reference, which means in the function f,
the same variable defined in the caller is used.

*/