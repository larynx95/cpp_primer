/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.19: Indicate which members of your Person class you would
declare as public and which you would declare as private. Explain your
choice.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.19.cpp
*/

#include <iostream>
#include <string>

struct Person {
  // Constructors which are part of interface should be public
  Person() = default;
  Person(const std::string &n) : name(n) {}
  Person(const std::string &n, const std::string &a) : name(n), address(a) {}
  Person(std::istream &);

  // member methods which are part of interface should be public
  std::string getName() const { return name; }
  std::string getAddress() const { return address; }

  // data members which are part of implementation shoule be private
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

int main() { return 0; }