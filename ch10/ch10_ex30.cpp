/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.30: Use stream iterators, sort, and copy to read a sequence
of integers from the standard input, sort them, and then write them back to
the standard output.

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.30.cpp

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
  std::copy(buffer.cbegin(), buffer.cend(), out_iter);
  std::cout << std::endl;
  return 0;
}