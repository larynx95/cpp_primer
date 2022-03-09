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
************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  /* new keyword */
  {
    int *pi = new int;  // pi points to a dynamically allocated,
                        // unnamed, uninitialized int

    string *ps = new string;  // initialized to empty string
    int *pi = new int;        // pi points to an uninitialized int
  }

  /* initializing a dynamically allocated object */
  {
    // (1) direct initializing
    // (2) traditional construction (parentheses)
    // (3) listinitializaton (curly bracket)
    // (4) following the type name with a pair of empty parens
    // (5) auto

    int *pi = new int(1024);  // object to which pi points has value 1024
    string *ps = new string(10, '9');  // *ps is "9999999999"
    // vector with ten elements with values from 0 to 9
    vector<int> *pv = new vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    string *ps1 = new string;   // default initialized to the empty string
    string *ps = new string();  // value initialized to the empty string
    int *pi1 = new int;         // default initialized; *pi1 is undefined
    int *pi2 = new int();       // value initialized to 0; *pi2 is 0

    /*
    auto p1 = new auto(obj);
    // p points to an object of the type of obj
    // that object is initialized from obj
    auto p2 = new auto {a, b, c};
    // error: must use parentheses for the initializer
    */
  }

  /* Dynamically Allocated const Objects */
  {
    // const object must be initialized!
    // allocate and initialize a const int
    const int *pci = new const int(1024);
    // allocate a default-initialized const empty string
    const string *pcs = new const string;
  }

  /* Memory Exhaustion */
  {
    // if allocation fails, new returns a null pointer
    int *p1 = new int;
    // if allocation fails, new throws std::bad_alloc
    int *p2 = new (nothrow) int;
    // if allocation fails, new returns a null pointer
  }

  /* Freeing Dynamic Memory */
  {
      // delete
  }

  /* Pointer Values and delete */
  {
    int i, *pi1 = &i, *pi2 = nullptr;
    double *pd = new double(33), *pd2 = pd;
    // delete i;    // error: i is not a pointer
    delete pi1;  // undefined: pi1 refers to a local
    delete pd;   // ok
    delete pd2;  // undefined: the memory pointed to by pd2 was already freed
    delete pi2;  // ok: it is always ok to delete a null pointer

    const int *pci = new const int(1024);
    delete pci;  // ok: deletes a const object
  }

  /* Dynamically Allocated Objects Exist until They Are Freed */
  {}

  return 0;
}