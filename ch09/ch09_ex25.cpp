/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.25: In the program on page 349 that erased a range of
elements, what happens if elem1 and elem2 are equal? What if elem2 or
both elem1 and elem2 are the off-the-end iterator?

Answer:
If elem1 and elem2 are equal, then no element will be removed from the
container.

If elem2 or both elem1 and elem2 are the off-the-end iterator, then all elements
from elem1 to the last element in the container will be removed.

*/

#include <iostream>
#include <vector>

int main() {
  //

  return 0;
}