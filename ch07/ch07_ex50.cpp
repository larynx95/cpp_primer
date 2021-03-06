/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.50: Determine whether any of your Person class constructors
should be explicit.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.50.cpp
*/

#include <iostream>
#include <string>

class Person {
  friend std::istream &read(std::istream &, Person &);
  // friend std::ostream &print(std::ostream &, const Person &);
 public:
  Person() = default;
  explicit Person(const std::string &n) : name(n) {}
  Person(const std::string &n, const std::string &a) : name(n), address(a) {}
  explicit Person(std::istream &);

  std::string getName() const { return name; }
  std::string getAddress() const { return address; }

 private:
  std::string name;
  std::string address;
};

std::istream &read(std::istream &is, Person &rhs) {
  is >> rhs.name >> rhs.address;
  return is;
}

std::ostream &print(std::ostream &os, const Person &rhs) {
  os << rhs.getName() << " " << rhs.getAddress();
  return os;
}

Person::Person(std::istream &is) { read(is, *this); }

int main() {
  Person p;
  read(std::cin, p);
  print(std::cout, p);

  return 0;
}