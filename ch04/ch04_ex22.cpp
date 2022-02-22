/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.22: Extend the program that assigned high pass, pass, and fail
grades to also assign low pass for grades between 60 and 75 inclusive. Write
two versions: One version that uses only conditional operators; the other
should use one or more if statements. Which version do you think is easier
to understand and why?

*/

#include <iostream>

int main() {
  int grade;
  std::cin >> grade;

  std::cout << (grade > 90
                    ? "high pass"
                    : grade > 75 ? "pass" : grade >= 60 ? "low pass" : "fail")
            << std::endl;

  // Note that the conditional operator is right associative, meaning that the
  // operands are grouped from right to left.

  if (grade > 90)
    std::cout << "high pass" << std::endl;
  else if (grade > 75)
    std::cout << "pass" << std::endl;
  else if (grade >= 60)
    std::cout << "low pass" << std::endl;
  else
    std::cout << "fail" << std::endl;

  // The `if` statements are relatively easy to understand when the conditions
  // do not have much braches.

  return 0;
}