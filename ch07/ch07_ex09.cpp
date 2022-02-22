/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.9: Add operations to read and print Person objects to the code
you wrote for the exercises in § 7.1.2 (p. 260).

*/

#include <iostream>
#include <string>

/**********************************************************
 * structure declaration, prototypes
 **********************************************************/

struct Person {
  std::string getName() const { return name; }
  std::string getAddress() const { return address; }

  std::string name;
  std::string address;
};

/**********************************************************
 * main function
 **********************************************************/

int main() {
  Person p1;
  read(std::cin, p1);
  print(std::cout, p1) << std::endl;

  return 0;
}

/**********************************************************
 * function definitions
 **********************************************************/

std::istream &read(std::istream &is, Person &rhs) {
  is >> rhs.name >> rhs.address;
  return is;
}

std::ostream &print(std::ostream &os, const Person &rhs) {
  os << rhs.getName() << " " << rhs.getAddress();
  return os;
}
