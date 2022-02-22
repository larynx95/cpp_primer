/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.44: Is the following declaration legal? If not, why not?

    vector<NoDefault> vec(10);

Answer:
It is illegal, the constructor of vector taken a single number will call the
default constructor of elements to value initialze its elements, but the class
of the elements NoDefault does not have a default constructor, thus the code
will not compile.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.44.md
*/
