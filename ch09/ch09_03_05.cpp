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
  // Table 9.9. Sequential Container Size Operations
  {
      /*
      c.resize(n)    Resize c so that it has n elems.
                     If n < c.size(), the excess elems are discarded.
                     If new elems must be added,
                     they are value intialized.
      c.resize(n,t)  Resize c to have n elems.
                     Any elems added have value t.
      */
  }

  // resize
  {
    list<int> ilist(10, 42);  // ten ints: each has value 42

    ilist.resize(15);  // adds five elements of value 0 to the back of ilist
    printList(ilist, ilist.begin(), ilist.end());

    ilist.resize(25, -1);  // adds ten elements of value -1 to the back of ilist
    printList(ilist, ilist.begin(), ilist.end());

    ilist.resize(5);  // erases 20 elements from the back of ilist
    printList(ilist, ilist.begin(), ilist.end());
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