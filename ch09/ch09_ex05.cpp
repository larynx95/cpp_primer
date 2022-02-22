/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.5: Rewrite the previous program to return an iterator to the
requested element. Note that the program must handle the case where the
element is not found.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.5.cpp

*/

#include <iostream>
#include <sstream>
#include <vector>

std::vector<int>::const_iterator hasValue(
    std::vector<int>::const_iterator begin,
    std::vector<int>::const_iterator end, int k) {
  for (auto it = begin; it != end; ++it)
    if (k == *it) return it;
  return end;
}

int main() {
  std::string str;
  std::getline(std::cin, str);
  std::istringstream iss(str);
  std::vector<int> vi;
  int k;
  while (iss >> k) vi.push_back(k);
  std::cin >> k;
  auto it = hasValue(vi.cbegin(), vi.cend(), k);
  if (it == vi.end())
    std::cout << "No found " << k << " in range" << std::endl;
  else
    std::cout << "Found " << *it << " at position " << it - vi.cbegin()
              << std::endl;

  return 0;
}