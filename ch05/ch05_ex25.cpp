/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 05. Statements

Exercise 5.25: Revise your program from the previous exercise to use a
try block to catch the exception. The catch clause should print a message
to the user and ask them to supply a new number and repeat the code inside
the try.

*/

#include <iostream>

int main() {
  int ival1, ival2;
  while (std::cout << "Enter two integer numbers for division:\n" &&
         std::cin >> ival1 >> ival2) {
    try {
      if (!ival2) throw std::runtime_error("ERROR: zero divisor");
      std::cout << ival1 / ival2 << '\n';
    } catch (std::runtime_error err) {
      std::cout << err.what() << "\nTry Again? (y/n) ";
      char c;
      if (!(std::cin >> c) || c == 'n') break;
    }
  }
  return 0;
}
