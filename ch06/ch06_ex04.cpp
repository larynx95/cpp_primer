/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.4: Write a function that interacts with the user, asking for a
number and generating the factorial of that number. Call this function from
main.

*/

#include <iostream>

int fact(int n) {  // Ignore overflow
  if (n < 1) return n;
  int k = n;
  while (--n) k *= n;
  return k;
}

int main() {
  int n;
  while (std::cin >> n) std::cout << n << "! = " << fact(n) << std::endl;

  return 0;
}