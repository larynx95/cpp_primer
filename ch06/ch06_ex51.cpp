/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.51: Write all four versions of f. Each function should print a
distinguishing message. Check your answers for the previous exercise. If your
answers were incorrect, study this section until you understand why your
answers were wrong.

*/

#include <iostream>

void f() { std::cout << " called f()" << std::endl; }

void f(int i) { std::cout << " called f(int)" << std::endl; }
void f(int i, int j) { std::cout << " called f(int, int)" << std::endl; }
void f(double d1, double d2 = 3.14) {
  std::cout << " called f(double, double)" << std::endl;
}

int main() {
  std::cout << "f(5.6)";
  f(5.6);
  // std::cout << "f(2.56, 42)";
  // f(2.56, 42);
  std::cout << "f(42)";
  f(42);
  std::cout << "f(42, 0)";
  f(42, 0);
  std::cout << "f(2.56, 3.14)";
  f(2.56, 3.14);

  return 0;
}