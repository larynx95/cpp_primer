/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.39: Would it be legal for both the constructor that takes a
string and the one that takes an istream& to have default arguments? If
not, why not?

Answer:
It is illegal for both constructors to have default arguments. If then, there
will be two default constructors, and that's an error.
https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.39.md
*/
