/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.56: What is a static class member? What are the advantages
of static members? How do they differ from ordinary members?

Answer:
https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.56.md

A static class member is a member that is associated with the class, rather than
with individual objects of the class type. It exists outside any object of the
class.

Advantages:
- Storage efficient.
- If a static member of a class changes, each object of the class will use the
new value of that static member. A static data member can have incomplete type.
- A static member (either a data member or a member function) can be used as a
default argument.

Differences between ordinary members and static members:
- A static member belongs to the class, an ordinary member belongs to objects
of the class.
*/
