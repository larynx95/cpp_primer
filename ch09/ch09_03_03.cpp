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
- The pop_front and pop_back Members
- Removing an Element from within the Container
- Removing Multiple Elements
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
  // Table 9.7. erase operations on sequential containers
  {
      /*
      c.pop_back()   Remove laset elem in c.
                     Undefined if c is empty. Returns void.
      c.pop_front()  Remove first elem in c.
                     Undefined if c is empty. Returns void.
      c.erase(p)     Remove the elem denoted by the iterator p
                     and returns an iterator to the elem
                     after the one denoted or the off-the-end iterator
                     if p denotes the last emem.
                     Undefined if p is the off-the-end iterator.
      c.erase(b,e)   Remove the range of elem denoted by the iterators b and e.
                     Returns an iterator to the elem after the last one
                     that was denoted, or an off-the-end iterator
                     if e is itself an off-the-end iteraotr.
      c.clear()      Remove all the elements in c.
                     Returns void.
      */
  }

  // The pop_front and pop_back Members
  {
    list<int> ilist;
    for (size_t ix = 0; ix != 3; ix++) ilist.push_back(ix);
    while (!ilist.empty()) {
      // process(ilist.front());  // do something with the current top of ilist
      cout << ilist.front() << endl;
      ilist.pop_front();  // done; remove the first element
    }
  }

  // Removing an Element from within the Container
  {
    list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = lst.begin();
    while (it != lst.end())
      if (*it % 2)           // if the element is odd
        it = lst.erase(it);  // erase this element
      else
        ++it;
  }

  // Removing Multiple Elements
  {
    list<string> slist = {"aa", "bb", "cc", "dd"};
    // delete the range of elements between two iterators
    // returns an iterator to the element just after the last removed element
    auto elem1 = slist.begin();
    auto elem2 = elem1;
    advance(elem2, 2);
    cout << "*elem1: " << *elem1 << endl;  // aa
    cout << "*elem2: " << *elem2 << endl;  // cc

    elem1 = slist.erase(elem1, elem2);  // after the call elem1 == elem2
    cout << "*elem1: " << *elem1 << endl;

    printList(slist, slist.begin(), slist.end());  // cc dd
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