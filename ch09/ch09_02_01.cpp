/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Section 9.1 Overview of the Sequential Containers
  - Constraints on Types That a Container Can Hold
Section 9.2 Container Library Overview
******************************************************************************/

/*
9.2.1. Iterators (Exercises 9.3~9.6)

- Iterator Ranges: `[ begin, end)`, left-includsive
  indicating that the range begins with begin and ends with,
  but does not include, end.

- Programming Implications of Using Left-Inclusive Ranges
  - If begin equals end, the range is empty
  - If begin is not equal to end, there is at least one element in the range,
    and begin refers to the first element in that range
  - We can increment begin some number of times until begin == end
*/

#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  // each container has three elements, initialized from the given initializers
  list<string> authors = {"Milton", "Shakespeare", "Austen"};
  vector<const char*> articles = {"a", "an", "the"};
  list<string> list2(authors);  // ok: types match
  // deque<string> authList(authors);  // error: container types don't match
  // vector<string> words(articles);   // error: element types must match
  // ok: converts const char* elements to string
  forward_list<string> words(articles.begin(), articles.end());

  return 0;
}

/*
Section 9.3 Sequential Container Operations
Section 9.4 How a vector Grows
Section 9.5 Additional string Operations
Section 9.6 Container Adaptors

*/