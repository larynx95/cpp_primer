/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 05. Statements

Exercise 5.5: Using an if–else statement, write your own version of the
program to generate the letter grade from a numeric grade.

*/

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> scores = {"F", "D", "C", "B", "A", "A++"};
  std::string lettergrade;
  int grade;

  while (std::cin >> grade) {
    lettergrade = (grade < 60)       ? scores[0]
                  : (grade == 100)   ? scores[(grade - 50) / 10]
                  : (grade % 10 > 7) ? scores[(grade - 50) / 10] + '+'
                  : (grade % 10 < 3) ? scores[(grade - 50) / 10] + '-'
                                     : scores[(grade - 50) / 10];
    std::cout << lettergrade + '\n';
  }
  return 0;
}
