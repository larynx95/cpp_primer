/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 05. Statements

Exercise 5.23: Write a program that reads two integers from the standard
input and prints the result of dividing the first number by the second.

*/

#include <iostream>

int main() {
  int ival1, ival2;
  while (std::cout << "Enter two integer numbers for division:\n" &&
         std::cin >> ival1 >> ival2)
    std::cout << ival1 / ival2 << '\n';
  return 0;
}