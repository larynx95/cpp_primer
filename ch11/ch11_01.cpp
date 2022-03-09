/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 11. Associative Containers

Section 11.1 Using an Associative Container
******************************************************************************/

/*
Elements Ordered by Key:
map        Associative array; holds key–value pairs
set        Container in which the key is the value
multimap   map in which a key can appear multiple times
multiset   set in which a key can appear multiple times

Unordered Collections:
unordered_map        map organized by a hash function
unordered_set        set organized by a hash function
unordered_multimap   Hashed map; keys can appear multiple times
unordered_multiset   Hashed set; keys can appear multiple times
*/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

void using_map() {
  map<string, size_t> word_count;  // empty map from string to size_t
  string word;
  cout << "Enter words (quie - 'q'): ";
  while (cin >> word) {
    if (word == "q") break;
    ++word_count[word];
  }
  for (const auto &w : word_count)
    cout << w.first << " occurs " << w.second
         << ((w.second > 1) ? " times" : " time") << endl;
}

void using_set() {
  // count the number of times each word occurs in the input
  map<string, size_t> word_count;  // empty map from string to size_t
  set<string> exclude = {"The", "But", "And", "Or", "An", "A",
                         "the", "but", "and", "or", "an", "a"};
  string word;
  while (cin >> word)
    // count only words that are not in exclude
    // Important! Idiom
    if (exclude.find(word) == exclude.end())
      ++word_count[word];  // fetch and increment the counter for word
}

int main() {
  /* using a map */
  using_map();

  /* using set */
  using_set();

  return 0;
}
