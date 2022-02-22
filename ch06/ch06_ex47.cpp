/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.47: Revise the program you wrote in the exercises in § 6.3.2 (p.
228) that used recursion to print the contents of a vector to conditionally
print information about its execution. For example, you might print the size of
the vector on each call. Compile and run the program with debugging
turned on and again with it turned off.

*/

#include <iostream>
#include <vector>

void printVecInt(const std::vector<int>::iterator bg,
                 const std::vector<int>::iterator ed) {
#ifndef NDEBUG
  std::cout << "In function: " << __func__ << ", "
            << "Vector size: " << ed - bg << std::endl;
#endif
  if (bg == ed) return;
  std::cout << *bg << std::endl;
  printVecInt(bg + 1, ed);
}

int main() {
  std::vector<int> vi;
  int i;
  while (std::cin >> i) vi.push_back(i);

  printVecInt(vi.begin(), vi.end());

  return 0;
}