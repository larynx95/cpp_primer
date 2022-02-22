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
  // Table 9.8. Operations to Insert or Remove Elements in a forward_list
  {
      /*
      ls.before_begin()       Iterator denoting the noneexistent elem
      ls.cbefore_begin()      just before the beginning of the list.
                              The iterator may bot be dereferenced.
                              cbefore_begin() returns a const_iterator.
      ls.insert_after(p,t)    Insert elem(s) after the one denoted by iterator
      p. ls.insert_after(p,n,t)  t is an object, n is a count, b and e are
      iterators ls.insert_after(p,b,e)  denoting a range (b and e must not
      refere to ls), ls.insert_after(p,il)   and il is a braced list. Return an
      iterator to the last inserted element. If the range is empty, return p.
                              Undefined if p is the off-the-end iterator.
      emplace_after(p,args)   Use args to construct an elem after the one
                              denoted by iterator p.
                              Return an iterator to the new elem.
                              Undefined if p is the off-the-end iterator.
      ls.erase_after(p)       Remove the elem after the one denoted by iterator
      p ls.erase_after(b,e)     or the range of elems from the one after the
      iterator b up to but not including the one denoted by e. Return an
      iterator to the elem after the one deleted, or the off-the-end iterator if
      there is no such elem. Undefined if p denotes the last elem in ls or is
      the off-the-end iterator.
      */
  }

  // two interators
  {
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin();  // denotes element "off the start" of flst
    auto curr = flst.begin();         // denotes the first element in flst
    while (curr != flst.end()) {  // while there are still elements to process
      if (*curr % 2)              // if the element is odd
        curr = flst.erase_after(prev);  // erase it and move curr
      else {
        prev = curr;  // move the iterators to denote the next
        ++curr;       // element and one before the next element
      }
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