/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.43: Assume we have a class named NoDefault that has a
constructor that takes an int, but has no default constructor. Define a class
C that has a member of type NoDefault. Define the default constructor for
C.
*/

#include <iostream>

class NoDefault {
 public:
  NoDefault(int i) : i_(i) {}

 private:
  int i_;
};

class C {
 public:
  C() : nd(0) {}

 private:
  NoDefault nd;
};

int main() {
  C c;
  return 0;
}