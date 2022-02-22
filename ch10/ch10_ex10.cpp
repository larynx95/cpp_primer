/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.10: Why do you think the algorithms don’t change the size of
containers?

Answer:
Because algorithms operate on a FIXED range of iterators. Changing the
size of a container would invalidate the iterators, in which case the algorithm
would have to refresh the iterators. This duplicates work and makes the
algorithm functions do more than what their name suggests or should. It is a
better design to leave the container related tasks (such as resizing) to the
container's operations.

*/
