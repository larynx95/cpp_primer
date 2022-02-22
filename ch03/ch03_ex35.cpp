/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.35: Using pointers, write a program to set the elements in an
array to zero.

************************************************************************************************************************************************************/

#include <iostream>
#include <iterator>
using namespace std;

int main() {
  int ia[10];
  for (const auto &e : ia) cout << e << ' ';
  cout << endl;

  for (int *bg = begin(ia), *ed = end(ia); bg != ed; ++bg) *bg = 0;

  for (const auto &e : ia) cout << e << ' ';
  cout << endl;

  return 0;
}