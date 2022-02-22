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
*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

// TODO: C++: How to pass any iterable type as a function parameter
// https://stackoverflow.com/questions/40647714/c-how-to-pass-any-iterable-type-as-a-function-parameter
template <typename Iter>
void printString(const string &str, Iter begin, Iter end);

template <typename Iter>
void printVec(vector<string> vec, Iter begin, Iter end);

template <typename Iter>
void printList(list<string> lst, Iter begin, Iter end);

template <typename Iter, typename T>
void printListGeneral(list<T> lst, Iter begin, Iter end);

// TODO: How to write a function that can take in an array or a vector?
// https://stackoverflow.com/questions/53252321/how-to-write-a-function-that-can-take-in-an-array-or-a-vector

int main() {
  list<string> a = {"Milton", "Shakespeare", "Austen"};
  auto it1 = a.begin();    // list<string>::iterator
  auto it2 = a.rbegin();   // list<string>::reverse_iterator
  auto it3 = a.cbegin();   // list<string>::const_iterator
  auto it4 = a.crbegin();  // list<string>::const_reverse_iterator

  const string str = "hello";
  printString(str, str.begin(), str.end());

  for (auto it = a.begin(); it != a.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;  // Milton Shakespeare Austen

  for (auto it = a.rbegin(); it != a.rend(); it++) {
    cout << *it << " ";
  }
  cout << endl;  // Austen Shakespeare Milton

  for (auto it = a.cbegin(); it != a.cend(); it++) {
    cout << *it << " ";
  }
  cout << endl;  // Milton Shakespeare Austen

  for (auto it = a.crbegin(); it != a.crend(); it++) {
    cout << *it << " ";
  }
  cout << endl;  // Austen Shakespeare Milton

  // type is explicitly specified
  list<string>::iterator it5 = a.begin();
  list<string>::const_iterator it6 = a.begin();
  // iterator or const_iterator depending on a's type of a
  auto it7 = a.begin();   // const_iterator only if a is const
  auto it8 = a.cbegin();  // it8 is const_iterator

  return 0;
}

template <typename Iter>
void printString(const string &str, Iter begin, Iter end) {
  begin = str.begin();
  end = str.end();
  for (begin; begin != end; begin++) {
    cout << "*begin: " << *begin << " ";
  }
  cout << endl;
}

template <typename Iter>
void printVec(vector<string> vec, Iter begin, Iter end) {
  begin = vec.begin();
  end = vec.end();
  for (begin; begin != end; begin++) {
    cout << "*begin: " << *begin << " ";
  }
  cout << endl;
}

template <typename Iter>
void printList(list<string> lst, Iter begin, Iter end) {
  begin = lst.begin();
  end = lst.end();
  for (begin; begin != end; begin++) {
    cout << "*begin: " << *begin << " ";
  }
  cout << endl;
}

template <typename Iter, typename T>
void printListGeneral(list<T> lst, Iter begin, Iter end) {
  begin = lst.begin();
  end = lst.end();
  for (begin; begin != end; begin++) {
    cout << "*begin: " << *begin << " ";
  }
  cout << endl;
}

/*
Section 9.3 Sequential Container Operations
Section 9.4 How a vector Grows
Section 9.5 Additional string Operations
Section 9.6 Container Adaptors

*/