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
- The Access Members Return References
- Subscripting and Safe Random Access
*/

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
  // Table 9.6. Operations to Access Elements in a Sequential Container
  {
      /*
      c.back()   Returns a reference to the last elem in c.
                 Undefined if c is empty.
      c.front()  Returns a reference to the first elem in c.
                 Undefined if c is empty.
      c[n]       Returns a reference to the elem indexed
                 by the unsigned integral value n.
                 Undefined if n >= c.size().
      c.at(n)    Returns a reference to the elem indexed by n.
                 If the index is out of range,
                 throws an out_of_range exeption.
      */
  }

  //
  {
    // check that there are elements before dereferencing an iterator or calling
    // front or back
    vector<int> c;
    if (!c.empty()) {
      // val and val2 are copies of the value of the first element in c
      auto val = *c.begin(), val2 = c.front();
      // val3 and val4 are copies of the of the last element in c
      auto last = c.end();
      auto val3 = *(--last);  // can't decrement forward_list iterators
      auto val4 = c.back();   // not supported by forward_list
    }
  }

  // The Access Members Return References
  {
    vector<int> c;
    if (!c.empty()) {
      c.front() = 42;      // assigns 42 to the first element in c
      auto &v = c.back();  // get a reference to the last element
      v = 1024;            // changes the element in c
      auto v2 = c.back();  // v2 is not a reference; it's a copy of c.back()
      v2 = 0;              // no change to the element in c
    }
  }

  // Subscripting and Safe Random Access
  {
    vector<string> svec;  // empty vector
    // cout << svec[0];      // run-time error: there are no elements in svec!
    // cout << svec.at(0);   // throws an out_of_range exception
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