/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 8. The IO Library

Exercise 8.1:
std::Write a function that takes and returns an istream&. The
function should read the stream until it hits end-of-file.
The function should print what it reads to the standard output.
Reset the stream so that it is valid before returning the stream.

https://github.com/chihyang/CPP_Primer/blob/master/chap08/Exer08_01.cpp

*/

#include <iostream>
#include <string>

std::istream& read(std::istream& is) {
  std::string word;
  while (!is.eof()) {
    is >> word;
    std::cout << word << std::endl;
  }
  is.clear();
  return is;
}

int main() {
  read(std::cin);
  return 0;
}