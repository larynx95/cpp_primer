/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 11. Associative Containers

Exercise 11.3:
Write your own version of the word-counting program.
******************************************************************************/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>

int main() {
  std::map<std::string, size_t> word_count;
  std::set<std::string> exclude = {"The", "But", "Or", "An", "A",
                                   "the", "but", "or", "an", "a"};
  std::string word;
  while (std::cin >> word)
    if (exclude.find(word) == exclude.end()) ++word_count[word];
  for (const auto &w : word_count)
    std::cout << w.first << " occurs " << w.second
              << ((w.second > 1) ? " times" : " time") << std::endl;
  return 0;
}

/*
TODO: map vs unordered_map in C++
https://www.geeksforgeeks.org/map-vs-unordered_map-c/

                  | map             | unordered_map
---------------------------------------------------------
Ordering        | increasing  order   | no ordering
                | (by default)        |

Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |

search time     | log(n)              | O(1) -> Average
                |                     | O(n) -> Worst Case

Insertion time  | log(n) + Rebalance  | Same as search

Deletion time   | log(n) + Rebalance  | Same as search
*/