/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.5: Write a program to read strings from the standard input,
concatenating what is read into one large string. Print the concatenated
string. Next, change the program to separate adjacent input strings by a
space.

******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

void concatenate() {
  string total, s;
  while (cin >> s) total += s;
  cout << total;
}

void concatenate_with_space() {
  string total, s;
  if (cin >> total) {
    while (cin >> s) total += ' ' + s;
  }
  cout << total;
}

int main() {
  // concatenate();
  // concatenate_with_space();

  return 0;
}