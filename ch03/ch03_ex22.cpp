/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.22: Revise the loop that printed the first paragraph in text to
instead change the elements in text that correspond to the first paragraph
to all uppercase. After you’ve updated text, print its contents.

getline()
https://en.cppreference.com/w/cpp/string/basic_string/getline
******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> text;

  std::string line;
  while (getline(std::cin, line)) text.push_back(line);

  for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    for (auto &c : *it) c = toupper(c);

  for (auto &elem : text)
    if (elem.empty())
      std::cout << std::endl;
    else
      std::cout << elem << " ";

  return 0;
}