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
- Using assign (Sequential Containers Only)
- Using swap
*/

#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  // Table 9.4. Container Assignment Operations
  {
      /*
      c1 = c2         Replace the elements in c1 with copies of the elements in
      c2 c1 and c2 must be the same type c = {a,b,c...}  Replace the elements in
      c1 with copies of the elements in the initializer list. (Not valid for
      array) swap(c1,c2)     Exchanges elements in c1 with those in c2.
      c1.swap(c2)     c1 and c2 must be the same type.
                      swap is usually much faster than
                      copying elements from c2 to c1.
      assign operations not valid for associative containers or array:
      seq.assign(b,e) Replace elements in seq with those
                      in the range denoted by iterators b and e.
                      The iterators b and e must not refere to elements in seq.
      seq.assign(il)  Replace the elements in seq with those
                      in the initializer list il
      seq.assign(n,t) Replace the elements in seq with n elements with value t.
      */
  }

  // unlike built-in arrays, the library array type does allow assignment.
  {
    array<int, 10> a1 = {0, 1, 2, 3, 4, 5};
    array<int, 10> a2 = {0};  // elements all have value 0
    a1 = a2;                  // replaces elements in a1
    a2 = {0};  // TODO: error: cannot assign to an array from a braced list
  }

  // Using assign (Sequential Containers Only)
  {
    // The call to assign replaces the elements in names
    // with copies of the elements in the range denoted by the iterators.
    // The arguments to assign determine how many elements
    // and what values the container will have.

    list<string> names;
    vector<const char*> oldstyle;
    // names = oldstyle;  // error: container types don't match
    // ok: can convert from const char*to string
    names.assign(oldstyle.cbegin(), oldstyle.cend());

    // A second version of assign takes an integral value and an element value.
    // It replaces the elements in the container
    // with the specified number of elements,
    // each of which has the specified element value:

    // equivalent to slist1.clear();
    // followed by slist1.insert(slist1.begin(), 10, "Hiya!");
    list<string> slist1(1);      // one element, which is the empty string
    slist1.assign(10, "Hiya!");  // ten elements; each one is Hiya !
  }

  // Using swap
  {
    // After the swap,
    // svec1 contains 24 string elements and svec2 contains ten.
    // With the exception of arrays,
    // swapping two containers is guaranteed to be fast
    // - the elements themselves are not swapped;
    // internal data structures are swapped.

    vector<string> svec1(10);  // vector with ten elements
    vector<string> svec2(24);  // vector with 24 elements
    swap(svec1, svec2);
  }

  return 0;
}

/*
Section 9.3 Sequential Container Operations
Section 9.4 How a vector Grows
Section 9.5 Additional string Operations
Section 9.6 Container Adaptors
*/