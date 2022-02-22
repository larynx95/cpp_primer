/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.8: What type should be used to read elements in a list of
strings? To write them?

Answer:
We can use
std::list<std::string>::const_iterator
or
std::list<std::string>::iterator
to read elements, and use
std::list<std::string>::iterator
to write them.
*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  //

  return 0;
}
