/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Section 9.1 Overview of the Sequential Containers
Section 9.2 Container Library Overview
Section 9.3 Sequential Container Operations
Section 9.4 How a vector Grows
Section 9.5 Additional string Operations
Section 9.6 Container Adaptors
******************************************************************************/

/*
- what is adaptor?
  What are Containers/Adapters? C++
  https://stackoverflow.com/questions/3873802/what-are-containers-adapters-c

  size_type       type large enough to hold the size of
                  the largest object of this type
  value_type      element type
  container_type  type of the underlying container
                  on which the adaptor is implemented
  A a;            create a new adaptor named a
  A a(c);         create a new adaptor named a
                  with a copy of the container c
  relational operators  each adaptor supports all the relational opeartors
  a.empty()       false if a hase any elements
  a.size()        number of elements in a
  swap(a,b)       swaps the contents of a and b
  a.swap(b)

- Defining an Adaptor

- Stack Adaptor

- The Queue Adaptors
*/