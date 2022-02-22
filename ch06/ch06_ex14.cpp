/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.14: Give an example of when a parameter should be a reference
type. Give an example of when a parameter should not be a reference.

Answer
Reference parameters

Functions must use reference parameters to operate on objects of a type that
cannot be copied.

Functions prefer to use reference parameters to operate on objects of large
class types or large containers.

Functions should use reference parameters to return additional information via
the reference parameters.

void printStr(std::ostream &os, const std::string &str, bool &stat) { if (os <<
str) stat = true; else stat = false; }

Nonreference parameters

Functions should use nonreference parameters when the value of the parameters
may changed but should not affect the objects passed to the function.

int sum(int n) { int sum = 0; while (n > 0) sum += n--; return sum; }

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch6/6.14.md

*/