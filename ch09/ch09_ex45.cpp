/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.45: Write a funtion that takes a string representing a name
and two other strings representing a prefix, such as “Mr.” or “Ms.” and a
suffix, such as “Jr.” or “III”. Using iterators and the insert and append
functions, generate and return a new string with the suffix and prefix
added to the given name.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.45.cpp

*/

#include <iostream>
#include <string>

std::string fixName(const std::string &name, const std::string &prefix,
                    const std::string &postfix) {
  std::string newName = name;
  std::string pref = prefix + " ";
  newName.insert(newName.begin(), pref.begin(), pref.end());
  return newName.append(" " + postfix);
}

int main() {
  std::cout << fixName("James", "Mr.", "Jr.") << std::endl;

  std::string name, prefix, postfix;
  std::cin >> name >> prefix >> postfix;
  std::cout << fixName(name, prefix, postfix) << std::endl;

  return 0;
}