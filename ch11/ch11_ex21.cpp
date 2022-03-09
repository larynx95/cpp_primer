/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 11. Associative Containers

Exercise 11.21:
Assuming word_count is a map from string to size_t and word
is a string, explain the following loop:
while (cin >> word)
++word_count.insert({word, 0}).first->second;
******************************************************************************/

/*
Answer:
std::map::insert
https://www.cplusplus.com/reference/map/map/insert/
return a pair,
with its member pair::first set to an iterator
pointing to either the newly inserted element
or to the element with an equivalent key in the map.
The pair::second element in the pair is set to true
if a new element was inserted
or false if an equivalent key already existed.

word_count.insert({word, 0}).first->second
------------------------------------------ (1)
----------------------------------- (2)
---------------------------- (3)
----------- (4)

(1): size_t
(2): std::map<std::string, size_t>::iterator
(3): std::pair<std::map<std::string, size_t>::iterator, bool>
(4): std::map<std::string, size_t>


Understanding the output of typeid().name()
https://stackoverflow.com/questions/16268090/understanding-the-output-of-typeid-name

typeid gives types m, j and Pj
https://stackoverflow.com/questions/62094206/typeid-gives-types-m-j-and-pj
https://gcc.gnu.org/onlinedocs/libstdc++/manual/ext_demangling.html
*/

#include <cxxabi.h>

#include <iostream>
#include <map>
#include <typeinfo>  //for 'typeid' to work

int main() {
  std::map<std::string, size_t> word_count;
  std::string word;

  while (std::cin >> word) {
    ++word_count.insert({word, 0}).first->second;
  }
  int status;
  std::cout << (typeid(word_count).name()) << std::endl;
  std::cout << abi::__cxa_demangle(typeid(word_count).name(), 0, 0, &status)
            << std::endl;
  std::cout << typeid(word_count.insert({"aa", 0})).name() << std::endl;
  std::cout << typeid(word_count.insert({"aa", 0}).first).name() << std::endl;
  std::cout << typeid(word_count.insert({"aa", 0}).first->first).name()
            << std::endl;
  std::cout << typeid(word_count.insert({"aa", 0}).first->second).name()
            << std::endl;
  std::cout << typeid(word_count.insert({"aa", 0}).second).name() << std::endl;

  for (const auto &w : word_count)
    std::cout << w.first << " occurs " << w.second
              << ((w.second > 1) ? " times" : " time") << '\n';
  return 0;
}