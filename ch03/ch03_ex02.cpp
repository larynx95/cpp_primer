/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.2: Write a program to read the standard input a line at a time.
Modify your program to read a word at a time.

******************************************************************************/

#include <iostream>
#include <string>

void read_lines() {
  std::string line;
  while (getline(std::cin, line)) std::cout << line << std::endl;
}

void read_words() {
  std::string word;
  while (std::cin >> word) std::cout << word << std::endl;
}

int main() {
  // read_lines();
  // read_words();

  return 0;
}