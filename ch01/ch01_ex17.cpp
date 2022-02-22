/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Exercise 1.17: What happens in the program presented in this section if the
input values are all equal? What if there are no duplicated values?

Answer:
If all equal, the count will be printed out.
If there are no duplicated values,
A new line will be printed when Enter clicked.
******************************************************************************/

#include <iostream>

int main() {
  int currVal = 0, val = 0;
  if (std::cin >> currVal) {
    int cnt = 1;
    while (std::cin >> val) {
      if (val == currVal)
        ++cnt;
      else {
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
        currVal = val;
        cnt = 1;
      }
    }
    std::cout << currVal << " occurs " << cnt << " times" << std::endl;
  }

  return 0;
}
