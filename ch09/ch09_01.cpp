/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Section 9.1 Overview of the Sequential Containers (Exercises 9.1)
******************************************************************************/

/*
  vector       flexible-size array.
               supports fast random access.
               inserting or deleting elements other than at the back
               may be slow
  deque        double-ended queue.
               supports fast random access
               fast insert/delete at front or back
  list         doubley linked list.
               supports only bidirectional sequential access
               fast insert/delete at any point int the list
  forward_list singly linked list.
               supports only sequential access in one direction
               fast insert/delete at any point in the list
  array        fixed-size array
               supports fast random access
               cannot add or remove elements
  string       a specialized container, similar to vector,
               that contains characters.
               rast random access.
               fast insert/delete at the back.

- Deciding Which Sequential Container to Use
*/

#include <iostream>
using namespace std;

int main() {
  //
  return 0;
}

/*
Section 9.2 Container Library Overview
Section 9.3 Sequential Container Operations
Section 9.4 How a vector Grows
Section 9.5 Additional string Operations
Section 9.6 Container Adaptors
*/