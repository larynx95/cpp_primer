/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 12. Dynamic Memory

Exercise 12.6:
Write a function that returns a dynamically allocated vector of
ints. Pass that vector to another function that reads the standard input to give
values to the elements. Pass the vector to another function to print the values
that were read. Remember to delete the vector at the appropriate time.
************************************************/

#include <iostream>
#include <memory>
#include <string>
#include <vector>

std::vector<int> *allocVector() { return new std::vector<int>(); }

void fillVector(std::istream &is, std::vector<int> *pv) {
  int i;
  while (is >> i) pv->push_back(i);
}

void printVector(std::ostream &os, std::vector<int> *pv) {
  for (auto &elem : *pv) os << elem << ' ';
}

int main() {
  auto *p = allocVector();
  fillVector(std::cin, p);
  printVector(std::cout, p);
  std::cout << std::endl;
  delete p;
  p = nullptr;
  std::cout << p << '\n';
  return 0;
}