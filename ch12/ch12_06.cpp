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
************************************************/

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main() {
  /*
  When we use a smart pointer, t
  he smart pointer class ensures that memory is freed
  when it is no longer needed
  even if the block is exited prematurely:

  case 1. smart pointer

    void f()
    {
      shared_ptr<int> sp(new int(42)); // allocate a new object
      // code that throws an exception that is not caught inside f
    } // shared_ptr freed automatically when the function ends

  case 2. not smart pointer

    void f()
    {
      int *ip = new int(42); // dynamically allocate a new object
      // code that throws an exception that is not caught inside f
      delete ip; // free the memory before exiting
    }
  */

  /*
  Smart Pointers and Dumb Classes

  struct destination;                // represents what we are connecting to
    struct connection;               // information needed to use the
  connection connection connect(destination*);  // open the connection
  void disconnect(connection);       // close the given connection
  void f(destination & d) {          // other parameters
    // get a connection; must remember to close it when done
    connection c = connect(&d);
    // use the connection
    // if we forget to call disconnect before exiting f,
    // there will be no way to close c
  }

  */

  return 0;
}