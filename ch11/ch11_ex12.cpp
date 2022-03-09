/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 11. Associative Containers

Exercise 11.12:
Write a program to read a sequence of strings and ints, storing each
into a pair. Store the pairs in a vector.
******************************************************************************/

#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
  std::vector<std::pair<std::string, int>> strInt;
  std::string word;
  int number;

  while (std::cin >> word && std::cin >> number)
    strInt.push_back({word, number});  // push list initialized pairs

  for (const auto &pair : strInt)
    std::cout << pair.first << ' ' << pair.second << '\n';
  return 0;
}
