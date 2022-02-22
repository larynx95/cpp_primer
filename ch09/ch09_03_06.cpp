/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Section 9.1 Overview of the Sequential Containers
Section 9.2 Container Library Overview
Section 9.3 Sequential Container Operations
******************************************************************************/

/*
9.3.1. Adding Elements to a Sequential Container (Exercises 9.18~22)
9.3.2. Accessing Elements (Exercises 9.23~24)
9.3.3. Erasing Elements (Exercises 9.25~9.26)
9.3.4. Specialized forward_list Operations (Exercises 9.27~9.28)
9.3.5. Resizing a Container (Exercises 9.29~9.30)
9.3.6. Container Operations May Invalidate Iterators (Exercises 9.31~9.34)
- Writing Loops That Change a Container
- Avoid Storing the Iterator Returned from end
*/

#include <forward_list>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Sales_data.h"
using namespace std;

template <typename Iter, typename T>
void printVec(vector<T> lst, Iter begin, Iter end);

template <typename Iter, typename T>
void printList(list<T> lst, Iter begin, Iter end);

int main() {
  // Writing Loops That Change a Container
  {
    // silly loop to remove even-valued elements and insert a duplicate of
    // odd-valued elements
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();  // call begin, not cbegin because we're changing vi
    while (iter != vi.end()) {
      if (*iter % 2) {
        iter = vi.insert(iter, *iter);  // duplicate the current element
        iter += 2;  // advance past this element and the one inserted before it
      } else
        iter = vi.erase(iter);  // remove even elements
      // don't advance the iterator; iter denotes the element after the one we
      // erased
    }
  }

  // Avoid Storing the Iterator Returned from end
  {
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // disaster: the behavior of this loop is undefined
    auto begin = v.begin(),
         end = v.end();  // bad idea, saving the value of the end iterator

    /*
    // (1)
    // The behavior of this code is undefined.
    // On many implementations, we’ll get an infinite loop.

    while (begin != end) {
      // do some processing
      // insert the new value and reassign begin,
      // which otherwise would be invalid
      ++begin;  // advance begin because we want to insert after this element
      begin = v.insert(begin, 42);  // insert the new value
      ++begin;  // advance begin past the element we just added
    }
    */

    // (2)
    // safer: recalculate end on each trip whenever the loop adds/erases
    // elements
    while (begin != v.end()) {
      // do some processing
      ++begin;  // advance begin because we want to insert after this element
      begin = v.insert(begin, 42);  // insert the new value
      ++begin;  // advance begin past the element we just added
    }
  }

  return 0;
}

// helper function: print vector
template <typename Iter, typename T>
void printVec(vector<T> lst, Iter begin, Iter end) {
  begin = lst.begin();
  end = lst.end();
  for (begin; begin != end; begin++) {
    cout << *begin << " ";
  }
  cout << endl;
}

// helper function: print list
template <typename Iter, typename T>
void printList(list<T> lst, Iter begin, Iter end) {
  begin = lst.begin();
  end = lst.end();
  for (begin; begin != end; begin++) {
    cout << *begin << " ";
  }
  cout << endl;
}

/*
Section 9.4 How a vector Grows
Section 9.5 Additional string Operations
Section 9.6 Container Adaptors
*/