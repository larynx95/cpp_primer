/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.23: How many arguments does bind take?

Answer:
bind is a variadic function, i.e. it uses an initializer list for parameters.
(p.220) The number of its arguments are unknown and varies depending on the
callable it is processing. What we could say is that bind takes the same number
of arguments of the callable's arguments plus 1--the name of callable itself.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.23.txt

*/