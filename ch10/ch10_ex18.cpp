/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.18: Rewrite biggies to use partition instead of find_if.
We described the partition algorithm in exercise 10.13 in § 10.3.1 (p.
387).
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void elimDups(std::vector<std::string> &words) {
  sort(words.begin(), words.end());
  auto end_uniqe = unique(words.begin(), words.end());
  words.erase(end_uniqe, words.end());
}

std::string make_plural(size_t ctr, const std::string &word,
                        const std::string &ending) {
  return (ctr > 1) ? word + ending : word;
}

void biggies(std::vector<std::string> &words,
             const std::vector<std::string>::size_type sz) {
  elimDups(words);
  stable_sort(words.begin(), words.end(),
              [](const std::string &s1, const std::string &s2) {
                return s1.size() < s2.size();
              });
  auto wc =
      partition(words.begin(), words.end(),
                [sz](const std::string &word) { return word.size() >= sz; });
  auto count = wc - words.begin();
  std::cout << count << ' ' << make_plural(count, "word", "s") << " of length "
            << sz << " or longer" << '\n';
  for_each(words.begin(), wc,
           [](const std::string &s) { std::cout << s << ' '; });
}

int main() {
  std::vector<std::string> words{"the",  "quick", "red",  "fox", "jumps",
                                 "over", "the",   "slow", "red", "turtle"};
  constexpr std::string::size_type size = 5;
  biggies(words, size);
  std::cout << std::endl;
  return 0;
}
