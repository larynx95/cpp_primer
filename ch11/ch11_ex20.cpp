/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 11. Associative Containers

Exercise 11.20:
Rewrite the word-counting program from § 11.1 (p. 421) to use
insert instead of subscripting. Which program do you think is easier to write
and read? Explain your reasoning.
******************************************************************************/

#include <iostream>
#include <map>

int main() {
  std::map<std::string, size_t> word_count;
  std::string word;

  while (std::cin >> word) {
    auto ret = word_count.insert({word, 0});
    ++ret.first->second;
  }
  for (const auto &w : word_count)
    std::cout << w.first << " occurs " << w.second
              << ((w.second > 1) ? " times" : " time") << '\n';
  return 0;
}
