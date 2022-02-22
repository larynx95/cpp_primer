/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.46: Rewrite the previous exercise using a position and length to
manage the strings. This time use only the insert function.
*/

#include <string>
#include <iostream>

std::string fixName(const std::string &name,
                    const std::string &prefix,
                    const std::string &postfix) {
  // An easy way.
  //std::string newName = prefix + " " + name + " " + postfix;
  //return newName;

  std::string newName = name;
  newName.insert(0, prefix + " ");
  return newName.insert(newName.size(), " " + postfix);
}

int main() {
  std::cout << fixName("James", "Mr.", "Jr.") << std::endl;

  std::string name, prefix, postfix;
  std::cin >> name >> prefix >> postfix;
  std::cout << fixName(name, prefix, postfix) << std::endl;

  return 0;
}