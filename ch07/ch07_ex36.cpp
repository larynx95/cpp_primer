/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.36: The following initializer is in error. Identify and fix the
problem.

struct X {
  X (int i, int j): base(i), rem(base % j) { }
  int rem, base;
};

Answer:
https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.36.md
The order of member initialization is the same with the order they appear in the
class definition. Since rem appears first, it will be initialized first. But the
value of base is undefined when rem is initialized, thus the value of rem is
undefined. To fix the problem, we can either switch the order of definitions of
rem and base or we can use the constructor parameters i and j direct initialize
rem(i % j).

TODO: check this again.
*/

#include <iostream>

struct X {
  X() = default;
  X(int i, int j) : base(i), rem(base % j) {}
  int rem, base;
};

int main() {
  struct X x1(10, 20);
  std::cout << x1.rem << " " << x1.base << std::endl;

  return 0;
}