/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Exercise 1.2:
Change the program to return -1.
A return value of -1 is often treated as an indicator that the program failed.
Recompile and rerun your program to see how your system treats a failure
indicator from main.

Difference between return 1, return 0, return -1 and exit?
https://stackoverflow.com/questions/22604196/difference-between-return-1-return-0-return-1-and-exit
******************************************************************************/

#include <iostream>  // header

int main() {
  std::cout << "return -1" << std::endl;
  return -1;
}