/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Section 9.1 Overview of the Sequential Containers
Section 9.2 Container Library Overview
Section 9.3 Sequential Container Operations
Section 9.4 How a vector Grows
- Members to Manage Capacity
- capacity and size
******************************************************************************/

/*
- Members to Manage Capacity

c.shrink_to_fit()   request to reduce capacity() to equal size()
c.capacity()        number of elements c can have
                    before reallocation is necessary
c.reserve(n)        allocate space for at least n elements

- capacity and size

    ```cpp
    vector<int> ivec;
    // size should be zero; capacity is implementation defined
    cout << "ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;
    // give ivec 24 elements
    for (vector<int>::size_type ix = 0; ix != 24; ++ix)
      ivec.push_back(ix);
    // size should be 24; capacity will be >= 24 and is implementation defined
    cout << "ivec: size: " << ivec.size()
         << " capacity: " << ivec.capacity() << endl;
    ```

*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  // how a vector grows
  {
      /* TODO:
      vector elems are stored contiguously to support fast random access.
      What must happen when we add an elem to a vector or a string?
      If there is no room for the new element,
      the container can’t just add an element somewhere else in memory
      - the elements must be contiguous.
      Instead, the container must allocate new memory
      to hold the existing elements plus the new one,
      move the elements from the old location into the new space,
      add the new element, and deallocate the old memory.
      If vector did this memory allocation and deallocation each time
      we added an element, performance would be unacceptably slow.

      To avoid these costs,
      library implementors use allocation strategies
      that reduce the number of times the container is reallocated.
      When they have to get new memory,
      vector and string implementations typically allocate capacity
      beyond what is immediately needed.
      The container holds this storage in reserve
      and uses it to allocate new elements as they are added.
      Thus, there is no need to reallocate the container for each new element.
      */
  }

  // Members to Manage Capacity
  {
      /*
      c.shrink_to_fit()   request to reduce capacity() to equal size()
      c.capacity()        number of elements c can have
                          before reallocation is necessary
      c.reserve(n)        allocate space for at least n elements
      */
  }

  // capacity and size
  {
    vector<int> ivec;
    // size should be zero; capacity is implementation defined
    cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity()
         << endl;

    // give ivec 24 elements
    for (vector<int>::size_type ix = 0; ix != 24; ++ix) ivec.push_back(ix);

    // size should be 24; capacity will be >= 24 and is implementation defined
    cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity()
         << endl;

    ivec.reserve(50);  // sets capacity to at least 50; might be more
    // size should be 24; capacity will be >= 50 and is implementation defined
    cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity()
         << endl;

    ivec.push_back(42);  // add one more element
    // size should be 51; capacity will be >= 51 and is implementation defined
    cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity()
         << endl;

    ivec.shrink_to_fit();  // ask for the memory to be returned
    // size should be unchanged; capacity is implementation defined
    cout << "ivec: size: " << ivec.size() << " capacity: " << ivec.capacity()
         << endl;
  }

  return 0;
}

/*
Section 9.5 Additional string Operations
Section 9.6 Container Adaptors

*/