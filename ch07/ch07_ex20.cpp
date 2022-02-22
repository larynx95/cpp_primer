/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.20: When are friends useful? Discuss the pros and cons of using
friends.

Answer:
A friend of a class can access nonpublic members of that class.

Pros: For functions that are part of the interface while not a member of the
class, they can access the nonpublic members of that class.

Cons: If the implementation of the class changes over time, its friend may also
requiring changes.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.20.md

*/
