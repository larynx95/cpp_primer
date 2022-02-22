/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.4: Write a class named Person that represents the name and
address of a person. Use a string to hold each of these elements.
Subsequent exercises will incrementally add features to this class.

*/

#include <string>

struct Person {
  std::string name;
  std::string address;
};

int main() { return 0; }