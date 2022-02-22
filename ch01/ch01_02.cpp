/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Section 1.1 Writing a Simple C++ Program
Section 1.2 A First Look at Input/Output
******************************************************************************/

#include <iostream>

int main() {
  /*
  1.2 A First Look at Input/Output
  (Exercises 1.3 ~ 1.6)

  iostream : istream + ostream
    istream : standard input
    ostream : standard output
  */

  std::cout << "Enter two numbers: " << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2
            << std::endl;

  return 0;
}

/*
Section 1.3 A Word about Comments
Section 1.4 Flow of Control
Section 1.5 Introducing Classes
Section 1.6 The Bookstore Program
*/