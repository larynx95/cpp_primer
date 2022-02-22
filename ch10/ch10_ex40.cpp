/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.40: What kinds of iterators do you think copy requires? What
about reverse or unique?

Answer:
The copy function requires a minimum input iterators for its first two arguments
and an output for its third (the destination iterator).

The reverse function requires a minimum a bidirectional iterators, because the
algorithm requires read, write, and multi-pass access, and bidirectional
movement through the container.

The unique function requires a minimum forward iterators, because the algorithm
requires read, write and multi-pass access, but not bidirectional movement
through the container.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.40.txt

*/