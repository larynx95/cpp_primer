/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.38: Write a program to explore how vectors grow in the library
you use.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.38.cpp
https://github.com/Mooophy/Cpp-Primer/blob/master/ch09/ex9_38.cpp

*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vi;
  std::cout << "Size: " << vi.size() << "\tCapacity : " << vi.capacity()
            << std::endl;

  vi.push_back(1);
  std::cout << "Size: " << vi.size() << "\tCapacity : " << vi.capacity()
            << std::endl;

  for (std::vector<int>::size_type ix = 0; ix != 100; ++ix) vi.push_back(ix);
  std::cout << "Size: " << vi.size() << "\tCapacity : " << vi.capacity()
            << std::endl;

  vi.shrink_to_fit();
  std::cout << "Size: " << vi.size() << "\tCapacity : " << vi.capacity()
            << std::endl;

  return 0;
}