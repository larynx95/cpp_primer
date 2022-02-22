/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Section 9.1 Overview of the Sequential Containers
  - Constraints on Types That a Container Can Hold
Section 9.2 Container Library Overview
******************************************************************************/

/*
9.2.1. Iterators (Exercises 9.3~9.6)
9.2.2. Container Type Members (Exercises 9.7~9.8)
9.2.3. begin and end Members (Exercises 9.9~9.10)
9.2.4. Defining and Initializing a Container (Exercises 9.11~9.13)
- Initializing a Container as a Copy of Another Container
- List Initialization
- Sequential Container Size-Related Constructors
- Library array s Have Fixed Size
*/

#include <array>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  // Initializing a Container as a Copy of Another Container
  {
    // each container has three elements, initialized from the given
    // initializers
    list<string> authors = {"Milton", "Shakespeare", "Austen"};
    vector<const char*> articles = {"a", "an", "the"};
    list<string> list2(authors);  // ok: types match
    // deque<string> authList(authors);  // error: container types don't match
    // vector<string> words(articles);   // error: element types must match
    // ok: converts const char* elements to string
    forward_list<string> words(articles.begin(), articles.end());
  }

  // List Initialization
  {
    // each container has three elements, initialized from the given
    // initializers
    list<string> authors = {"Milton", "Shakespeare", "Austen"};
    vector<const char*> articles = {"a", "an", "the"};
  }

  // Sequential Container Size-Related Constructors
  {
    vector<int> ivec(10, -1);      // ten int elements, each initialized to  -1
    list<string> svec(10, "hi!");  // ten strings; each element is "hi!"
    forward_list<int> ivec(10);    // ten elements, each initialized to 0
    deque<string> svec(10);        // ten elements, each an empty string
  }

  // Library array s Have Fixed Size
  {
    array<int, 42>;     // type is: array that holds 42 ints
    array<string, 10>;  // type is: array that holds 10 strings
    // array<int, 10>::size_type i;    // array type includes element type and
    // size array<int>::size_type j;   // error: array<int> is not a type

    array<int, 10> ia1;  // ten default-initialized ints
    array<int, 10> ia2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // list initialization
    array<int, 10> ia3 = {42};  // ia3[0] is 42, remaining elements are 0

    int digs[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int cpy[10] = digs;  // error: no copy or assignment for built-in arrays
    array<int, 10> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> copy = digits;  // ok: so long as array types match
  }

  return 0;
}

/*
Section 9.3 Sequential Container Operations
Section 9.4 How a vector Grows
Section 9.5 Additional string Operations
Section 9.6 Container Adaptors

*/