/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.31: The program on page 354 to remove even-valued elements
and duplicate odd ones will not work on a list or forward_list. Why?
Revise the program so that it works on these types as well.

https://github.com/Mooophy/Cpp-Primer/blob/master/ch09/ex9_31_1.cpp

*/

#include <iostream>
#include <list>

using std::advance;
using std::cout;
using std::list;

auto remove_evens_and_double_odds(list<int>& data) {
  for (auto cur = data.begin(); cur != data.end();)
    if (*cur & 0x1)
      cur = data.insert(cur, *cur), advance(cur, 2);
    else
      cur = data.erase(cur);
}

int main() {
  list<int> data{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  remove_evens_and_double_odds(data);
  for (auto i : data) cout << i << " ";

  return 0;
}