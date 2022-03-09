/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 11. Associative Containers

Exercise 11.8:
Write a program that stores the excluded words in a vector
instead of in a set. What are the advantages to using a set?
******************************************************************************/

#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  std::map<std::string, size_t> word_count;
  std::string word;
  std::vector<std::string> exclude{"the", "but", "and", "or", "an", "a"};
  while (std::cin >> word) {
    word.front() = tolower(word.front());
    if (ispunct(word.back())) word.pop_back();
    if (find(exclude.cbegin(), exclude.cend(), word) == exclude.end())
      ++word_count[word];
  }
  for (const auto &w : word_count)
    std::cout << w.first << " occurs " << w.second
              << ((w.second > 1) ? " times" : " time") << '\n';
  return 0;
}
