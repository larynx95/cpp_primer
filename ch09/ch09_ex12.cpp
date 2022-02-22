/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.12: Explain the differences between
  the constructor that takes a container to copy
  and
  the constructor that takes two iterators.

Answer:
The constructor that takes a container to copy requires the container type and
the element type of the two containers are both match exactly.

The constructor that takes two iterators requires the element type of the source
container must be compatible with the element type of the destiny container.

For example,

      #include <list>
      #include <vector>

      struct A {
      };

      struct B {
          B(A a) {}  // type A can covert to type B
      };

      int main() {
          std::vector<A> va;
          std::vector<B> vb;

          //std::list<A> la(vb.begin(), vb.end());  // Error, convert B to A
          std::list<B> lb(va.begin(), va.end());  // OK, convert A to B

          return 0;
      }

The requirement of the former constructor is stricter than the latter.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.12.md

*/

#include <list>
#include <vector>

struct A {};

struct B {
  B(A a) {}  // type A can covert to type B
};

int main() {
  std::vector<A> va;
  std::vector<B> vb;

  // std::list<A> la(vb.begin(), vb.end());  // Error, convert B to A
  std::list<B> lb(va.begin(), va.end());  // OK, convert A to B

  return 0;
}
