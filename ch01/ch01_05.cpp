/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Section 1.1 Writing a Simple C++ Program
Section 1.2 A First Look at Input/Output
Section 1.3 A Word about Comments
Section 1.4 Flow of Control
Section 1.5 Introducing Classes
******************************************************************************/

#include <iostream>

#include "Sales_item.h"

int main() {
  /*
  1.5. Introducing Classes

  1.5.1. The Sales_item Class
  (Exercises 1.20 ~ 1.21)

  Implementing Sales_item class
  */

  Sales_item book;
  std::cin >> book;
  std::cout << book << std::endl;

  /*
  1.5.2. A First Look at Member Functions
  (Exercises 1.23 ~ 1.24)
  */

  Sales_item item1, item2;
  std::cin >> item1 >> item2;
  if (item1.isbn() == item2.isbn()) {
    std::cout << item1 + item2 << std::endl;
  } else {
    std::cerr << "Data must refere to same ISBN" << std::endl;
    return -1;
  }

  return 0;
}

/*
Section 1.6 The Bookstore Program
*/