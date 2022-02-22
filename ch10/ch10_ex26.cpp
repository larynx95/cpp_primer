/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.26: Explain the differences among the three kinds of insert
iterators.

Answer:
back_inserter, front_inserter and inserter are analogous to c.push_pack,
push_front and c.insert container operations. In fact, whenever we create one
of these insert iterators, it calls its corresponding container operation to
handle the insertion into a container. Therefore, the way these iterators
insert and refresh the iterator in the elements range resembles the operation
each iterator uses.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.26.txt

*/