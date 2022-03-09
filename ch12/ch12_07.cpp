/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 12. Dynamic Memory

Section 12.1 Dynamic Memory and Smart Pointers
  12.1.1 The shared_ptr Class
    The make_shared function
    Copying and assigning shared_ptrs
    shared_ptr automatically destroy their objects ...
    ... and Automatically Free the Associated Memory
    Defining the StrtBlob class
    Copying, Assigning, and Destroying StrBlobs
  12.1.2 Managing Memory Directly
    Using new to Dynamically Allocate and Initialize Objects
    Dynamically Allocated const Objects
    Memory Exhaustion
    Freeing Dynamic Memory
    Pointer Values and delete
    Dynamically Allocated Objects Exist until They Are Freed
    Resetting the Value of a Pointer after a delete ...
    ... Provides Only Limited Protection
  12.1.3 Using shared_ptrs with new
    Don’t Mix Ordinary Pointers and Smart Pointers ...
    ... and Don’t Use get to Initialize or Assign Another Smart Pointer
  12.1.4 Smart Pointers and Exceptions
    Smart Pointers and Dumb Classes
    Using Our Own Deletion Code
  12.1.5 unique_ptr
************************************************/

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main() { return 0; }