/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.22: Update your Person class to hide its implementation.

*/

#include <iostream>
#include <string>

/**********************************************************
 * class declaration, prototypes
 **********************************************************/

class Person {
  friend std::istream &read(std::istream &, Person &);
  // friend std::ostream &print(std::ostream &, const Person &);
 public:
  Person() = default;
  Person(const std::string &n) : name(n) {}
  Person(const std::string &n, const std::string &a) : name(n), address(a) {}
  Person(std::istream &);

  std::string getName() const { return name; }
  std::string getAddress() const { return address; }

 private:
  std::string name;
  std::string address;
};

std::ostream &print(std::ostream &os, const Person &rhs);

/**********************************************************
 * main function
 **********************************************************/

int main() {
  Person p;
  read(std::cin, p);
  print(std::cout, p);

  return 0;
}

/**********************************************************
 * function definitions
 **********************************************************/
std::istream &read(std::istream &is, Person &rhs) {
  is >> rhs.name >> rhs.address;
  return is;
}

Person::Person(std::istream &is) { read(is, *this); }

std::ostream &print(std::ostream &os, const Person &rhs) {
  os << rhs.getName() << " " << rhs.getAddress();
  return os;
}