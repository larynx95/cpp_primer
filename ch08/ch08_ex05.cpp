/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 8. The IO Library

Exercise 8.5: Rewrite the previous program to store each word in a
separate element.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch8/8.5.cpp
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> read(const std::string &filename) {
  std::ifstream in(filename);
  std::vector<std::string> vs;
  if (in) {
    for (std::string s; in >> s;) vs.push_back(s);
  } else {
    std::cerr << "Fail to open file: " << filename << std::endl;
  }
  return vs;
}

int main() {
  std::string filename;
  std::cin >> filename;
  auto vs = read(filename);
  for (decltype(vs.size()) i = 0; i != vs.size(); ++i)
    std::cout << i + 1 << "\t: " << vs[i] << std::endl;

  return 0;
}