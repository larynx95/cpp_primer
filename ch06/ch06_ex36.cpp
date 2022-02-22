/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.36: Write the declaration for a function that returns a reference
to an array of ten strings, without using either a trailing return,
decltype, or a type alias.

*/

#include <string>
using std::string;

string (&foo1())[10];