/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 8. The IO Library

Exercise 8.9: Use the function you wrote for the first exercise in § 8.1.2 (p.
314) to print the contents of an istringstream object.

https://github.com/chihyang/CPP_Primer/blob/master/chap08/Exer08_09.cpp

*/

#include <iostream>
#include <sstream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::istringstream;
using std::string;

istream& read(istream& is) {
  string word;
  while (!is.eof()) {
    is >> word;
    cout << word << endl;
  }
  is.clear();
  return is;
}

int main() {
  string str = "John has a book.";
  istringstream is(str);
  read(is);

  return 0;
}