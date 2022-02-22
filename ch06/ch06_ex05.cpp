/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.5: Write a function to return the absolute value of its argument.

*/

#include <iostream>
using namespace std;

int myabs(int);

int main() {
  cout << myabs(-100) << endl;
  return 0;
}

int myabs(int n) { return (n >= 0) ? n : -n; }