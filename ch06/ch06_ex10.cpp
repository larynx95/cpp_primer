/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.10: Using pointers, write a function to swap the values of two
ints. Test the function by calling it and printing the swapped values.

*/

#include <iostream>

void swapInt(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void swapIntRef(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  swapIntRef(a, b);
  std::cout << a << " " << b << std::endl;

  return 0;
}