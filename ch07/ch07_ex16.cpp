/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.16: What, if any, are the constraints on where and how often an
access specifier may appear inside a class definition? What kinds of members
should be defined after a public specifier? What kinds should be private?

Answer:
There is no constraint on where and how often an access specifier may appear
inside a class definition. A class may contain zero or more access specifiers,
each kind of access specifiers can appears multiple times. There is no
constraint on the sequence of access specifiers too.

The constructors and member functions that are part of the interface should be
defined after a public specifier.

The data members and member functions that are part of the implementation should
be defined after a private specifier.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.16.md

*/
