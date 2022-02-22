/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.28: Copy a vector that holds the values from 1 to 9 inclusive,
into three other containers. Use an inserter, a back_inserter, and a
front_inserter, respectivly to add elements to these containers. Predict
how the output sequence varies by the kind of inserter and verify your
predictions by running your programs.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.28.cpp

*/

#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>  // iota
#include <string>
#include <vector>
using namespace std;

int main() {
  // use iota (p. 882) to populate the source vector with values 1-9.
  vector<int> source(9);
  iota(source.begin(), source.end(), 1);
  // back_inserter: output 1 2 3 4 5 6 7 8 9
  vector<int> ivec;
  copy(source.cbegin(), source.cend(), back_inserter(ivec));
  // front inserter: output 9 8 7 6 5 4 3 2 1
  deque<int> ideq;
  copy(source.cbegin(), source.cend(), front_inserter(ideq));
  // inserter: output 1 2 3 4 5 6 7 8 9
  list<int> ilist;
  copy(source.cbegin(), source.cend(), inserter(ilist, ilist.begin()));

  // print the containers
  cout << "back_inserter and vector:";
  for (const auto &elem : ivec) cout << ' ' << elem;
  cout << '\n';

  cout << "front_inserter and deque:";
  for (const auto &elem : ideq) cout << ' ' << elem;
  cout << '\n';

  cout << "inserter and list:";
  for (const auto &elem : ilist) cout << ' ' << elem;
  cout << '\n';

  return 0;
}