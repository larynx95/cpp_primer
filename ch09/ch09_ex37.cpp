/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.37: Why don’t list or array have a capacity member?

Answer:
A list does not support random access, and element of list is stored seperately
in memory. There is no need to reallocate its elements, and thus no need to
preallocate memory. So the "capacity" of a list is the same with its size.

An array has a fixed size, there is also no need to reallocate its elements, and
thus no need to preallocate memory. So the "capacity" of an array is the same
with its size too.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.37.md

*/

#include <vector>

int main() {
  //

  return 0;
}