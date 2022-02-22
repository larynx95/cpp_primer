/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Section 9.1 Overview of the Sequential Containers
Section 9.2 Container Library Overview
******************************************************************************/

/*
9.2.1. Iterators (Exercises 9.3~9.6)
9.2.2. Container Type Members (Exercises 9.7~9.8)
9.2.3. begin and end Members (Exercises 9.9~9.10)
9.2.4. Defining and Initializing a Container (Exercises 9.11~9.13)
9.2.5. Assignment and swap (Exercises 9.14)
9.2.6. Container Size Operations
9.2.7. Relational Operators (Exercises 9.15~9.17)
- Relational Operators Use Their Element’s Relational Operator
*/

#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

#include "Sales_data.h"
using namespace std;

int main() {
  // relational operators
  {
    // Every container type supports the equality operators (== and !=).
    // all the containers except the unordered associative containers
    // also support the relational operators (>, >=, <, <=).

    vector<int> v1 = {1, 3, 5, 7, 9, 12};
    vector<int> v2 = {1, 3, 9};
    vector<int> v3 = {1, 3, 5, 7};
    vector<int> v4 = {1, 3, 5, 7, 9, 12};

    cout << (v1 < v2) << endl;   // 1, true; v1 and v2 differ at element [2]:
                                 // v1[2] is less than v2[2]
    cout << (v1 < v3) << endl;   // 0, false; all elements are equal,
                                 // but v3 has fewer of them;
    cout << (v1 == v4) << endl;  // 1, true; each element is equal
                                 // and v1 and v4 have the same size()
    cout << (v1 == v2) << endl;  // 0, false; v2 has fewer elements than v1
  }

  // Relational Operators Use Their Element’s Relational Operator
  {
    vector<Sales_data> storeA, storeB;
    // if (storeA < storeB) // error: Sales_data has no less-than operator
  }

  return 0;
}

/*
Section 9.3 Sequential Container Operations
Section 9.4 How a vector Grows
Section 9.5 Additional string Operations
Section 9.6 Container Adaptors
*/