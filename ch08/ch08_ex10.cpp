/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 8. The IO Library

Exercise 8.10: Write a program to store each line from a file in a
vector<string>. Now use an istringstream to read each element from
the vector a word at a time.

https://github.com/chihyang/CPP_Primer/blob/master/chap08/Exer08_10.cpp

*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cerr;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cerr << "Wrong input!" << endl;
    return -1;
  }

  ifstream input(argv[1]);
  string line, stmp;
  vector<string> text;
  while (getline(input, line)) {
    text.push_back(line);
  }

  for (const auto &s : text) {
    istringstream is(s);  // element in text is a line of string, not a word
    while (is >> stmp)    // read each word in a line
    {
      cout << stmp << " ";  // output each word
    }
    cout << endl;  // this way the output is the completely the same as the
                   // input file
  }

  return 0;
}