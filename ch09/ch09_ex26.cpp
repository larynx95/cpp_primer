/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.26: Using the following definition of ia, copy ia into a vector
and into a list. Use the single-iterator form of erase to remove the
elements with odd values from your list and the even values from your
vector.

int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

https://github.com/Mooophy/Cpp-Primer/blob/master/ch09/ex9_26.cpp
TODO: What is the 0x1 in if statement?

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.26.cpp

*/

#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  std::vector<int> iv(std::begin(ia), std::end(ia));
  std::list<int> il(std::begin(ia), std::end(ia));

  std::cout << "Before erase:" << std::endl;
  std::cout << "vector iv: ";
  for (const auto &i : iv) std::cout << i << " ";
  std::cout << std::endl;

  std::cout << "list   il: ";
  for (const auto &i : il) std::cout << i << " ";
  std::cout << std::endl;

  for (auto it = iv.begin(); it != iv.end();)
    if (*it % 2)
      ++it;
    else
      it = iv.erase(it);

  for (auto it = il.begin(); it != il.end();)
    if (*it % 2)
      it = il.erase(it);
    else
      ++it;

  std::cout << "After erase:" << std::endl;
  std::cout << "vector iv: ";
  for (const auto &i : iv) std::cout << i << " ";
  std::cout << std::endl;

  std::cout << "list   il: ";
  for (const auto &i : il) std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}