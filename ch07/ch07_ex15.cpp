/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.15: Add appropriate constructors to your Person class.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.15.cpp
*/

#include <iostream>
#include <string>

/**********************************************************
 * structure declaration, prototypes
 **********************************************************/

struct Person {
  Person() = default;
  Person(const std::string &n) : name(n) {}
  Person(const std::string &n, const std::string &a) : name(n), address(a) {}
  Person(std::istream &);

  std::string getName() const { return name; }
  std::string getAddress() const { return address; }

  std::string name;
  std::string address;
};

std::istream &read(std::istream &is, Person &rhs);
std::ostream &print(std::ostream &os, const Person &rhs);

/**********************************************************
 * main function
 **********************************************************/

int main() {
  Person p1;
  Person p2("Zhang San");
  Person p3("Zhang San", "Earth");
  Person p4(std::cin);

  print(std::cout, p1) << std::endl;
  print(std::cout, p2) << std::endl;
  print(std::cout, p3) << std::endl;
  print(std::cout, p4) << std::endl;

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

Person::Person(std::istream &is) { read(is, *this); }