/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.13: What is the value of j in the following program?
    int i = 42;        // global variable
    int main() {
        int i = 100;   // local variable
        int j = i;
    }

*/

#include <iostream>

int main() {
  int i = 42;  // global variable
  int main() {
    int i = 100;  // local variable
    int j = i;
  }
  std::cout << j << std::endl;  // 100

  return 0;
}