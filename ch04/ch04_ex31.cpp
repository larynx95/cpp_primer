/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.31: The program in this section used the prefix increment and
decrement operators. Explain why we used prefix and not postfix. What
changes would have to be made to use the postfix versions? Rewrite the
program using postfix operators.

*/

#include <iostream>
#include <vector>

int main() {
  std::vector<int> ivec(10);
  std::vector<int>::size_type cnt = ivec.size();
  for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
    ivec[ix] = cnt;
  for (const auto &e : ivec) std::cout << e << " ";
  std::cout << std::endl;

  // Because we don't need the value returned by postfix operator, and making a
  // copy of an object may be a heavy operation, so prefix operator is prefered
  // here.

  cnt = ivec.size();
  for (std::vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
    ivec[ix] = cnt;
  for (const auto &e : ivec) std::cout << e << " ";
  std::cout << std::endl;

  // The results are same.

  return 0;
}