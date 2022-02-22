/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.2: Define a list that holds elements that are deques that hold
ints.

*/

#include <deque>
#include <iostream>
#include <list>

int main() {
  std::list<std::deque<int>> ldi;
  std::cout << std::endl;

  return 0;
}