/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Section 9.1 Overview of the Sequential Containers
Section 9.2 Container Library Overview
Section 9.3 Sequential Container Operations
******************************************************************************/

/*
9.3.1. Adding Elements to a Sequential Container (Exercises 9.18~22)
- Using push_back
- Using push_front
- Adding Elements at a Specified Point in the Container
- Inserting a Range of Elements
- Using the Return from insert
- Using the Emplace Operations
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
  // Table 9.5. operations That Add Elements to a Sequential Container
  {
      /*
    c.push_back(t)        Creates an elem with value t or constructed from args
    c.emplace_back(args)  at the end of c. Returns void.
    c.push_front(t)       Creates an elem with value t or consturcted from args
    c.emplace_front(args) on the front of c. Returns void.
    c.insert(p,t)         Creates an elem with value t or constructed from args
    c.emplace(p,args)     before the leme denoted by iterator p.
                          Returns an iterator referring to the elem
                          that was added.
    c.insert(p,n,t)       Inserts n elems with value t before the elem denoted
                          by iterator p.
                          Returns an iterator to the first elem inserted;
                          if n is zero, returns p.
    c.insert(p,b,e)       Inserts the elems from the range denoted by
                          iterators b and e before the elem denoted
                          by iterator p. b and e may not refer to elems in c.
                          Returns an iterator to the first elem inserted;
                          if the range is empty, returns p.
    c.insert(p,il)        il is a braced list of elem values.
                          Inserts the given values before the elem denoted
                          by the iterator p.
                          Returns an iterator to the first inserted elem;
                          if the list is empty returns p.
    */
  }

  // Using push_back
  {
    string word;
    vector<string> container;
    cout << "Enter a string: ";
    while (cin >> word) {
      container.push_back(word);
      cout << "Enter a string: ";
      if (container.size() > 5) break;
    }

    printVec(container, container.begin(), container.end());
  }

  // Using push_front
  {
    list<int> ilist;
    // add elements to the start of ilist
    for (size_t ix = 0; ix != 4; ++ix) ilist.push_front(ix);

    printList(ilist, ilist.begin(), ilist.end());  // 3 2 1 0
  }

  // Adding Elements at a Specified Point in the Container
  {
    list<string> slist;
    for (size_t ix = 0; ix != 4; ++ix) slist.push_front(to_string(ix) + "!");
    auto iter = slist.begin();
    iter++;
    slist.insert(iter, "Hello!");  // insert "Hello!" just before iter

    printList(slist, slist.begin(), slist.end());  // 3! Hello! 2! 1! 0!
  }

  // Inserting a Range of Elements
  {
    vector<string> svec;
    svec.insert(svec.end(), 10, "Anna");
    printVec(svec, svec.begin(), svec.end());
    // Anna Anna Anna Anna Anna Anna Anna Anna Anna Anna

    vector<string> v = {"quasi", "simba", "frollo", "scar"};
    // insert the last two elements of v at the beginning of slist
    list<string> slist;
    for (size_t ix = 0; ix != 4; ++ix) slist.push_front(to_string(ix) + "!");

    slist.insert(slist.begin(), v.end() - 2, v.end());
    //                          ----(1)----- --(2)--- ==>  ( (1), (2) ]
    slist.insert(slist.end(),
                 {"these", "words", "will", "go", "at", "the", "end"});
    // run-time error: iterators denoting the range to copy from
    // must not refer to the same container as the one we are changing
    slist.insert(slist.begin(), slist.begin(), slist.end());

    printList(slist, slist.begin(), slist.end());
  }

  // Using the Return from insert
  {
    string word;
    list<string> lst;
    auto iter = lst.begin();
    cout << "Enter a string: ";
    while (cin >> word) {
      iter = lst.insert(iter, word);  // same as calling push_front
      cout << "Enter a string: ";
      if (lst.size() > 3) break;
    }
  }

  // Using the Emplace Operations
  {
    /* TODO: Fix this.
    // construct a Sales_data object at the end of c
    // uses the three-argument Sales_data constructor
    c.emplace_back("978-0590353403", 25, 15.99);

    // error: there is no version of push_back that takes three arguments
    // c.push_back("978-0590353403", 25, 15.99);

    // ok: we create a temporary Sales_data object to pass to push_back
    c.push_back(Sales_data("978-0590353403", 25, 15.99));

    // iter refers to an element in c, which holds Sales_data elements
    c.emplace_back();  // uses the Sales_data default constructor
    c.emplace(iter, "999-999999999");  // uses Sales_data(string)
    // uses the Sales_data constructor that takes an ISBN, a count, and a price
    c.emplace_front("978-0590353403", 25, 15.99);
    */
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