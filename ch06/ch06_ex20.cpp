/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.20: When should reference parameters be references to const?
What happens if we make a parameter a plain reference when it could be a
reference to const?

Answer:
If the reference parameters will not be changed inside function, then they
should be reference to const.

If we make a parameter a plain reference, then we can not pass

- a const object,
- or a literal,
- or an object that requires conversion to a plain reference parameter.

*/