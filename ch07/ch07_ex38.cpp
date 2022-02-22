/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.38: We might want to supply cin as a default argument to the
constructor that takes an istream&. Write the constructor declaration that
uses cin as a default argument.

*/

#include <iostream>
#include <string>

/**********************************************************
 * class definition, prototypes
 **********************************************************/

class Apple;

class Apple {
  friend std::istream &read(std::istream &, Apple &);
  friend std::ostream &print(std::ostream &, const Apple &);

 public:
  Apple(std::istream &is = std::cin) { read(is, *this); }

 private:
  std::string name;
  int fresh = 0;
  int rotten = 0;
};

/**********************************************************
 * main function
 **********************************************************/

int main() {
  // TODO: finish this exercise
  Apple apple1();

  return 0;
}

/**********************************************************
 * function definitions
 **********************************************************/

std::istream &read(std::istream &is, Apple &apl) {
  double price;
  is >> apl.name >> apl.fresh >> apl.rotten;
  return is;
}

std::ostream &print(std::ostream &os, const Apple &apl) {
  os << apl.name << " " << apl.fresh << " " << apl.rotten << std::endl;
  return os;
}
