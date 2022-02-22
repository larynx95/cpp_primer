/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.32: Indicate whether the following function is legal. If so, explain
what it does; if not, correct any errors and then explain it.

int &get(int *arry, int index) { return arry[index]; }
int main() {
  int ia[10];
  for (int i = 0; i != 10; ++i)
    get(ia, i) = i;
}
*/

#include <iostream>

int &get(int *arry, int index) { return arry[index]; }

// The function is legal. It return a reference to the element at `index` in
// array `arry`. The reference return is lvalue, thus can be used to assign to
// the array.

int main() {
  int ia[10];
  for (int i = 0; i != 10; ++i) get(ia, i) = i;

  for (int i = 0; i != 10; ++i) std::cout << ia[i] << " ";
  std::cout << std::endl;

  return 0;
}