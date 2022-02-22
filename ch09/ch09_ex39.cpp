/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.39: Explain what the following program fragment does:

    vector<string> svec;
    svec.reserve(1024);
    string word;
    while (cin >> word)
      svec.push_back(word);
    svec.resize(svec.size()+svec.size()/2);

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> svec;
  svec.reserve(1024);  // Preallocate memory for 1024 `string`s
  string word;
  while (cin >> word)  // Read stirngs into `svec`
    svec.push_back(word);
  svec.resize(svec.size() + svec.size() / 2);
  // Reallocate memory, if current capacity is greater then this argument,
  // nothing happened, else expand the size to at least the same as the
  // argument.

  return 0;
}