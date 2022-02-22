/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.17: Read a sequence of words from cin and store the values a
vector. After you’ve read all the words, process the vector and change
each word to uppercase. Print the transformed elements, eight words to a
line.

******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> sv;
  std::string s;
  while (std::cin >> s) sv.push_back(s);
  for (auto &elem : sv)
    for (auto &c : elem) c = toupper(c);
  for (decltype(sv.size()) i = 0; i != sv.size(); ++i) {
    std::cout << sv[i] << '\t';
    if ((i + 1) % 8 == 0) std::cout << std::endl;
  }

  return 0;
}