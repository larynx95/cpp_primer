/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.48: Given the definitions of name and numbers on page 365,
what does numbers.find(name) return?

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.48.cpp

*/

#include <iostream>
#include <string>

int main() {
  std::string numbers("0123456789"), name("r2d2");
  auto pos = numbers.find(name);  // std::string::npos
  if (pos != std::string::npos)
    std::cout << pos << std::endl;
  else
    std::cout << "npos" << std::endl;

  return 0;
}