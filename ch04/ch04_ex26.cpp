/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.26: In our grading example in this section, what would happen if
we used unsigned int as the type for quiz1?

Answer:
The standard guarantees the minimum size of int is 16 bits, and the minimum size
of long is 32 bits. Since the teacher has 30 students in a class, which needs at
least 30 bits, int would be not enough to hold all the results.
*/

#include <string>
using std::string;

int main() {
  //

  return 0;
}