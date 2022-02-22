/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.22: Write a function to swap two int pointers.

*/

#include <iostream>

void swapIntPtr(int **pa, int **pb) {
  int *tmp = *pa;
  *pa = *pb;
  *pb = tmp;
}

void swapIntPtr(int *&pa, int *&pb) {
  int *tmp = pa;
  pa = pb;
  pb = tmp;
}

int main() {
  int i = 1, j = 2;
  int *pi = &i, *pj = &j;
  std::cout << "pi = " << pi << " *pi = " << *pi << std::endl;
  std::cout << "pj = " << pj << " *pj = " << *pj << std::endl;
  swapIntPtr(&pi, &pj);
  std::cout << "pi = " << pi << " *pi = " << *pi << std::endl;
  std::cout << "pj = " << pj << " *pj = " << *pj << std::endl;
  swapIntPtr(pi, pj);
  std::cout << "pi = " << pi << " *pi = " << *pi << std::endl;
  std::cout << "pj = " << pj << " *pj = " << *pj << std::endl;

  return 0;
}