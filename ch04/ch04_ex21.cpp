/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.21: Write a program to use a conditional operator to find the
elements in a vector<int> that have odd value and double the value of
each such element.

*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> iv;
  int i;
  while (std::cin >> i) iv.push_back(i);
  for (auto &elem : iv) elem = elem % 2 ? elem + elem : elem;
  for (const auto &elem : iv) std::cout << elem << ' ';
  std::cout << std::endl;

  return 0;
}