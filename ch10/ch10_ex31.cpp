/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.31: Update the program from the previous exercise so that it
prints only the unique elements. Your program should use unqiue_copy (§
10.4.1, p. 403).

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.31.cpp

*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
  std::istream_iterator<int> in_iter(std::cin), eof;
  std::ostream_iterator<int> out_iter(std::cout, " ");
  std::vector<int> buffer(in_iter, eof);
  std::sort(buffer.begin(), buffer.end());
  std::unique_copy(buffer.cbegin(), buffer.cend(), out_iter);
  std::cout << std::endl;
  return 0;
}