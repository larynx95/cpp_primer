/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.41: Write a program that initializes a string from a
vector<char>.

*/

#include <vector>
#include <string>
#include <iostream>

int main() {
  std::vector<char> vc{'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
  std::string str(vc.cbegin(), vc.cend());

  std::cout << str << std::endl;

  return 0;
}