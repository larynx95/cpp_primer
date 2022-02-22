/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.3: Write and test your own version of fact.

*/

#include <iostream>
using namespace std;

int fact(int n) {
  if (n == 1) return n;
  return n * fact(n - 1);
}

int main() {
  int n;
  cout << "Enter a integer value: " << endl;
  std::cin >> n;
  std::cout << n << "! = " << fact(n) << std::endl;

  return 0;
}