/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.20: The library defines an algorithm named count_if. Like
find_if, this function takes a pair of iterators denoting an input range and
a predicate that it applies to each element in the given range. count_if
returns a count of how often the predicate is true. Use count_if to rewrite
the portion of our program that counted how many words are greater than
length 6.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.20.cpp

*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending) {
  return (ctr > 1) ? word + ending : word;
}

string conjugate(size_t ctr, const string &singular, const string &plural) {
  return (ctr > 1) ? plural : singular;
}

int main() {
  vector<string> words{"the", "quick", "red", "fox",    "jumps",   "over",
                       "the", "slow",  "red", "turtle", "sixteen", "times"};
  constexpr string::size_type size{6};
  auto count = count_if(words.begin(), words.end(),
                        [&](const string &word) { return word.size() > size; });
  cout << count << make_plural(count, " word", "s")
       << conjugate(count, " has ", " have ") << "more than " << size
       << " letters" << '\n';
  return 0;
}