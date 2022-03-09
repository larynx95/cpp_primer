/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 11. Associative Containers

Exercise 11.17:
Assuming c is a multiset of strings and v is a vector of strings,
explain the following calls.
Indicate whether each call is legal:

copy(v.begin(), v.end(), inserter(c, c.end()));
copy(v.begin(), v.end(), back_inserter(c));
copy(c.begin(), c.end(), inserter(v, v.end()));
copy(c.begin(), c.end(), back_inserter(v));
******************************************************************************/

/*
C++, copy set to vector
https://stackoverflow.com/questions/5034211/c-copy-set-to-vector

std::back_inserter for a std::set?
https://stackoverflow.com/questions/908272/stdback-inserter-for-a-stdset
*/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

template <typename T>
void print_vec(std::vector<T> vec) {
  for (auto iter = vec.begin(); iter != vec.end(); iter++) {
    std::cout << *iter << std::endl;
  }
}

int main() {
  std::set<double> input;
  input.insert(5);
  input.insert(6);

  std::vector<double> output;
  std::copy(input.begin(), input.end(), std::back_inserter(output));
  print_vec(output);
}