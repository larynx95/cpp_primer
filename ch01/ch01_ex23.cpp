/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Exercise 1.23: Write a program that reads several transactions and counts
how many transactions occur for each ISBN.

******************************************************************************/

#include <iostream>

#include "Sales_item.h"

int main() {
  Sales_item currItem, valItem;
  if (std::cin >> currItem) {
    int cnt = 1;
    while (std::cin >> valItem) {
      if (valItem.isbn() == currItem.isbn())
        ++cnt;
      else {
        std::cout << currItem << " occurs " << cnt << " times " << std::endl;
        currItem = valItem;
        cnt = 1;
      }
    }

    std::cout << currItem << " occurs " << cnt << " times " << std::endl;
  }
  return 0;
}
