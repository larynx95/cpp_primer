/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.19: Rewrite the program from the previous exercise to use a
list. List the changes you needed to make.

*/

#include <deque>
#include <iostream>
#include <list>  // 1. Include header
#include <string>

int main() {
  std::list<std::string> words;
  std::string word;
  while (std::cin >> word) words.push_back(word);

  for (auto it = words.cbegin(); it != words.cend(); ++it)
    std::cout << *it << std::endl;

  return 0;
}