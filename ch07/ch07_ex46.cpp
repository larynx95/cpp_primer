/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.46: Which, if any, of the following statements are untrue? Why?

(a) A class must provide at least one constructor.
(b) A default constructor is a constructor with an empty parameter list.
(c) If there are no meaningful default values for a class, the class should not
provide a default constructor.
(d) If a class does not define a default constructor, the compiler generates
one that initializes each data member to the default value of its associated
type.

Answer:
https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.46.md

(a) A class must provide at least one constructor.

True. If the programmer doesn't provide any constructor, the compiler will
synthesise one default constructor.

(b) A default constructor is a constructor with an empty parameter list.

Untrue. A constructor of which all parameters have default values also defines a
default constructor.

(c) If there are no meaningful default values for a class, the class should not
provide a default constructor.

True. <!--- Need more consideration. --->

(d) If a class does not define a default constructor, the compiler generates one
that initializes each data member to the default value of its associated type.

Untrue. Only if a class does not define any constructors, will the compiler
generate synthesised default constructor.

*/
