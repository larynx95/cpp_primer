/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.7: Write a function that returns 0 when it is first called and then
generates numbers in sequence each time it is called again.

*/

#include <iostream>
using namespace std;

int foo() {
  static int cnt = 0;
  return cnt++;
}

int main() {
  cout << foo() << endl;  // 0
  cout << foo() << endl;  // 1
  cout << foo() << endl;  // 2
  return 0;
}