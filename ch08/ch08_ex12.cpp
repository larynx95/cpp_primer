/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 8. The IO Library

Exercise 8.12: Why didn’t we use in-class initializers in PersonInfo?

Answer:
Because the synthesised default constructor will be called when an object of
class PersonInfo is created, which will default initialized its data members.
Meanwhile, both string and vector have default constructors, and will be used
when default initialized. Thus, we don't need in-class initializers to initialze
data members in PersonInfo.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch8/8.12.md

*/