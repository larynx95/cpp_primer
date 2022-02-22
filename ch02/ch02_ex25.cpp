/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.25: Determine the types and values of each of the following
variables.

(a) int* ip, &r = ip;
(b) int i, *ip = 0;
(c) int* ip, ip2;

typeif operator
https://en.cppreference.com/w/cpp/language/typeid

*/

#include <iostream>

int main() {
  {
    int *ip, i, &r = i;  // `ip` is `int *`, `i` is `int`, `r` is `int &`
    std::cout << "(a)" << std::endl;
    std::cout << "ip\t" << typeid(ip).name() << std::endl;  // ip  Pi
    std::cout << "i\t" << typeid(i).name() << std::endl;    // i   i
    std::cout << "r\t" << typeid(r).name() << std::endl;    // r   i
    // Note that `typeid` will lose the `const` qualifier and reference
  }
  {
    int i, *ip = 0;  // `i` is `int`, `ip` is `int *`
    std::cout << "(b)" << std::endl;
    std::cout << "i\t" << typeid(i).name() << std::endl;    // i   i
    std::cout << "ip\t" << typeid(ip).name() << std::endl;  // ip  Pi
  }
  {
    int *ip, ip2;  // `ip` is `int *`, `ip2` is `int`
    std::cout << "(c)" << std::endl;
    std::cout << "ip\t" << typeid(ip).name() << std::endl;    // ip   Pi
    std::cout << "ip2\t" << typeid(ip2).name() << std::endl;  // ip2  i
  }

  return 0;
}