/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.8: Why does read define its Sales_data parameter as a plain
reference and print define its parameter as a reference to const?


Answer:
The read function will change its Sales_data parameter and pass the information
back via plain reference.

The print function won't change its Sales_data parameter, and by using a
reference to const, we can print const Sales_data object as well.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.8.md

*/
