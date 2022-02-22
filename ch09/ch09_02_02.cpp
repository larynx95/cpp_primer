/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Section 9.1 Overview of the Sequential Containers
  - Constraints on Types That a Container Can Hold
Section 9.2 Container Library Overview
******************************************************************************/

/*
9.2.1. Iterators (Exercises 9.3~9.6)
9.2.2. Container Type Members (Exercises 9.7~9.8)
*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  // iter is the iterator type defined by list<string>
  list<string>::iterator iter;

  // count is the difference_type type defined by vector<int>
  // TODO: How can I use `difference_type`?
  vector<int>::difference_type count;

  return 0;
}

/*
Section 9.3 Sequential Container Operations
Section 9.4 How a vector Grows
Section 9.5 Additional string Operations
Section 9.6 Container Adaptors

*/