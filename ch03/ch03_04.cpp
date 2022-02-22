/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 3. Strings, Vectors, and Arrays

Section 3.1 Namespace using Declarations
Section 3.2 Library string Type
Section 3.3 Library vector Type
Section 3.4 Introducing Iterators
******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  /********************************************************
  3.4.1. Using Iterators
  ********************************************************/

  // iterator operators
  {
    /*
    *iter          : return a reference to iterator iter
    iter->mem      : == (*iter).mem
    ++iter         : increment iter to refer to the next elem
    --iter         : decrement iter to refer to the previous elem
    iter1 == iter2 : compare
    iter1 != iter2 : compare
    */

    string s("some string");
    if (s.begin() != s.end()) {  // make sure s is not empty
      auto it = s.begin();       // it denotes the first character in s
      *it = toupper(*it);        // make that character uppercase
    }
    cout << "String s is now: " << s << endl;
  }

  // moving iterator from one element to another
  {
    string s("some string");
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
      // TODO: it != s.end() vs. it < s.end()
      *it = toupper(*it);  // capitalize the current
    cout << "String s is now: " << s << endl;
  }

  // iterator type
  {
      /*
      vector<int>::iterator it;  // it can read and write vector<int> elements
      string::iterator it2;      // it2 can read and write characters in a
      string vector<int>::const_iterator it3; // it3 can read but not write
      elements string::const_iterator it4;      // it4 can read but not write
      characters
      */

      // const_iterator  : const
      // iterator        : non-const
  }

  // the begin and end operations
  {
    // The type returned by begin and end depends on
    // whether the object on which they operator is const.
    // If the object is const, then begin and end return a const_iterator;
    // if the object is not const, they return iterator

    vector<int> v;
    const vector<int> cv;
    auto it1 = v.begin();   // it1 has type vector<int>::iterator
    auto it2 = cv.begin();  // it2 has type vector<int>::const_iterator
    auto it3 = v.cbegin();  // it3 has type vector<int>::const_iterator
  }

  // combining dereference and member access
  {
    // (1) string

    string str = "abc";
    auto iter = str.cbegin();
    cout << "*iter: " << *iter << endl;    // *iter: 0
    cout << typeid(*iter).name() << endl;  // character
    cout << typeid(iter).name() << endl;   // iterator

    // (2) vector of strings

    // (*it).empty()  : (O) - (*it) has member "empty()" function
    // *it.empty()    : (X) - (it) doesn't have "empty()" function
    // it->empty()    : (O)

    vector<string> text = {"a", "an", "the"};
    auto it = text.cbegin();
    cout << "*it: " << *it << endl;      // *it: a
    cout << typeid(*it).name() << endl;  // Ss (g++ type)
    cout << typeid(it).name() << endl;   // iterator

    for (auto it = text.cbegin(); it != text.cend() && it->empty(); ++it)
      cout << *it << endl;

    // TODO: What does the type Ss mean? (g++ type names)
    // https://stackoverflow.com/questions/27595350/what-does-the-type-ss-mean
  }

  /********************************************************
  3.4.2. Iterator Arithmetic (binary search)
  (Exercises 3.24 ~ 3.26)
  ********************************************************/

  // operations supported by vector and string iterators
  {
      /*
      iter + n    :
      iter - n    :
      iter1 += n  :
      iter1 -= n  :
      iter1 = iter 2
      >,>=,<,<=
      */
  }

  // arithmetic operations on iterators
  {
    string vi("0123456");
    //         ---|---     <-- mid index

    // compute an iterator to the element closest to the midpoint of vi
    auto mid = vi.begin() + vi.size() / 2;
    cout << "*mid: " << *mid << endl;  // *mid: 3

    // process elememts in the first half of vi
    for (auto it = vi.begin(); it != vi.end(); ++it) {
      if (it < mid) {
        cout << *it << " ";
      }
    }
    cout << endl;  // 0 1 2
  }

  // using iterator arithmetic (Binary search algorithm)
  {
    // text must be sorted
    // beg and end will denote the range we're searching
    // TODO: complete this code
    //       what is the prrequisites for this code? sorting?
    string text("0123456789");
    char sought = '3';
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end - beg) / 2;  // original midpoint
    // while there are still elements to look at and we haven't yet found sought
    while (mid != end && *mid != sought) {
      if (sought < *mid)  // is the element we want in the first half?
        end = mid;        // if so, adjust the range to ignore the second half
      else                // the element we want is in the second half
        beg = mid + 1;    // start looking with the element just after mid
      mid = beg + (end - beg) / 2;  // new midpoint
      cout << "*mid: " << *mid << endl;
    }
  }

  return 0;
}

/*
Section 3.5 Arrays
Section 3.6 Multidimensional Arrays
*/