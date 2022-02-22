/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.16: Repeat the previous program, but compare elements in a
list<int> to a vector<int>.

https://github.com/Mooophy/Cpp-Primer/blob/master/ch09/ex9_16.cpp

*/

#include <iostream>
#include <list>
#include <vector>

int main() {
  std::list<int> li{1, 2, 3, 4, 5};
  std::vector<int> vec2{1, 2, 3, 4, 5};
  std::vector<int> vec3{1, 2, 3, 4};

  std::cout << (std::vector<int>(li.begin(), li.end()) == vec2 ? "true"
                                                               : "false")
            << std::endl;
  std::cout << (std::vector<int>(li.begin(), li.end()) == vec3 ? "true"
                                                               : "false")
            << std::endl;

  return 0;
}