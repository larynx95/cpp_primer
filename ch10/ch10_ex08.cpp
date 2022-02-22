/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.8: We said that algorithms do not change the size of the
containers over which they operate. Why doesn’t the use of back_inserter
invalidate this claim?

Answer:
Because an assignment through an back_inserter iterator calls the push_back
operation.  (p.382) That is, the insertion (or resizing) is handled by the
container's operation and not the algorithm.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.08.txt

*/