/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.36: In the following code, determine the type of each variable
and the value each variable has when the code finishes:

    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;

* Remember that decltype(( variable )) (note, double parentheses) is always
a reference type, but decltype( variable ) is a reference type only if variable
is a reference.

*/

#include <iostream>

int main() {
  int a = 3, b = 4;
  decltype(a) c = a;    // `c` is `int`
  decltype((b)) d = a;  // `d` is `int &` to a
  std::cout << a << " " << b << " " << c << " " << d << std::endl;  // 3 4 3 3
  ++c;
  std::cout << a << " " << b << " " << c << " " << d << std::endl;  // 3 4 4 3
  ++d;
  std::cout << a << " " << b << " " << c << " " << d << std::endl;  // 4 4 4 4

  return 0;
}