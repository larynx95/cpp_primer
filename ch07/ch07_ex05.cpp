/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.5: Provide operations in your Person class to return the name
and address. Should these functions be const? Explain your choice.

*/

#include <string>

struct Person {
  std::string getName() const { return name; }
  std::string getAddress() const { return address; }

  std::string name;
  std::string address;
};

// The member function `getName` and `getAddress` should be `const`, because
// they don't change the object.

int main() { return 0; }