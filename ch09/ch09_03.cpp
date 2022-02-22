/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Section 9.1 Overview of the Sequential Containers
Section 9.2 Container Library Overview
Section 9.3 Sequential Container Operations
******************************************************************************/

/*
9.3.2. Accessing Elements

  c.back()   returns a reference to the last element in c.
             indefined if c is empty
  c.front()  returns a reference to the first element in c.
             undefined if c is empty
  c[n]       retuns a reference to the element indexed
             by the unsigned itegral value n.
             undefined if n >= c.size()
  c.at(n)    returns a reference to the element indexed by n
             if the index is out of range,
             throws an out_of_range exception

- The Access Members Return References

    ```cpp
    // check that there are elements
    // before dereferencing an iterator or calling front or back
    if (!c.empty()) {
    // val and val2 are copies of the value of the first element in c
    auto val = *c.begin(), val2 = c.front();
    // val3 and val4 are copies of the of the last element in c
    auto last = c.end();
    auto val3 = *(--last); // can't decrement forward_list iterators
    auto val4 = c.back(); // not supported by forward_list
    }
    ```

- The Access Members Return References

    ```cpp
    if (!c.empty()) {
      c.front() = 42;     // assigns 42 to the first element in c
      auto &v = c.back(); // get a reference to the last element
      v = 1024;           // changes the element in c
      auto v2 = c.back(); // v2 is not a reference; it's a copy of c.back()
      v2 = 0;             // no change to the element in c
    }
    ```

- Subscripting and Safe Random Access

9.3.3. Erasing Elements

  c.pop_back()    removes last element in c
  c.pop_front()   removes first element in c
  c.erase(p)      removes the element denoted by the iterator p
                  and returns an iterator to the element after the one deleted
                  or the off-the-end iterator
                  if p denoteds the last element
  c.erase(b, e)   removes the range of elements denoted by the iterators b and e
  c.clear()       removes all the elements in c

- The pop_front and pop_back Members

- Removing an Element from within the Container

    ```cpp
    list<int> lst = {0,1,2,3,4,5,6,7,8,9};
    auto it = lst.begin();
    while (it != lst.end())
      if (*it % 2) // if the element is odd
        it = lst.erase(it); // erase this element
      else
        ++it;
    ```

- Removing Multiple Elements

    ```cpp
    // delete the range of elements between two iterators
    // returns an iterator to the element just after the last removed element
    elem1 = slist.erase(elem1, elem2); // after the call elem1 == elem2
    slist.clear(); // delete all the elements within the container
    slist.erase(slist.begin(), slist.end()); // equivalent
    ```

9.3.4. Specialized forward_list Operations

  lst.before_begin()
  lst.cbefore_begin()
  lst.insert_after(p,t)
  lst.insert_after(p,n,t)
  lst.insert_after(p,b,e)
  lst.insert_after(p,il)
  emplace_after(p, args)
  lst.erase_after(p)
  lst.erase_after(b, e)

  ```cpp
  forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
  auto prev = flst.before_begin(); // denotes element "off the start" of flst
  auto curr = flst.begin();        // denotes the first element in flst
  while (curr != flst.end()) {     // while there are still elements to process
    if (*curr % 2) // if the element is odd
      curr = flst.erase_after(prev); // erase it and move curr
    else {
      prev = curr;                // move the iterators to denote the next
      ++curr;                     // element and one before the next
      element
    }
  }
  ```

9.3.5. Resizing a Container

9.3.6. Container Operations May Invalidate Iterators

- Avoid Storing the Iterator Returned from end

    ```cpp
    // disaster: the behavior of this loop is undefined
    auto begin = v.begin(),
    end = v.end(); // bad idea, saving the value of the end iterator
    while (begin != end) {
      // do some processing
      // insert the new value and reassign begin,
      // which otherwise would be invalid
      ++begin; // advance begin because we want to insert after this element
      begin = v.insert(begin, 42); // insert the new value
      ++begin; // advance begin past the element we just added
    }
    ```

    ```cpp
    // safer: recalculate end on each trip
    // whenever the loop adds/erases elements
    while (begin != v.end()) {
      // do some processing
      ++begin; // advance begin because we want to insert after this element
      begin = v.insert(begin, 42); // insert the new value
      ++begin; // advance begin past the element we just added
    }
    ```

*/

#include <iostream>

/*
Section 9.4 How a vector Grows
Section 9.5 Additional string Operations
Section 9.6 Container Adaptors

*/