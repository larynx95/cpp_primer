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
************************************************/

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main() {
  /* initialize smart pointer */
  {
    shared_ptr<double> p1;            // shared_ptr that can point at a double
    shared_ptr<int> p2(new int(42));  // p2 points to an int with value 42
  }

  /* we cannot implicitly convert a built-in pointer to a smart pointer */
  {
    // we must use the direct form of initialization

    // shared_ptr<int> p1 = new int(1024);
    // error: must use direct initialization
    shared_ptr<int> p2(new int(1024));
    // ok: uses direct initialization
  }

  /* Don’t Mix Ordinary Pointers and Smart Pointers ...

        // ptr is created and initialized when process is called
        void process(shared_ptr<int> ptr){
          // use ptr
        } // ptr goes out of scope and is destroyed

    The parameter to process is passed by value,
    so the argument to process is copied into ptr.
    Copying a shared_ptr increments its reference count.
    Thus, inside process the count is at least 2.
    (1: when created, 2: copied)
    When process completes,
    the reference count of ptr is decremented but cannot go to zero.
    Therefore, when the local variable ptr is destroyed,
    the memory to which ptr points will not be deleted.
  */

  /* The right way to use this function is to pass it a shared_ptr:

    shared_ptr<int> p(new int(42));     // reference count is 1
    process(p);     // copying p increments its count; in process the reference
                    // count is 2
    int i = *p;     // ok: reference count is 1
  */

  /*
  Table 12.3: Other Ways to Define and Change shared_ptrs

  shared_ptr<T>         p(q) p manages the object to which the built-in pointer
                        q points; q must point to memory allocated by new and
                        must be convertible to T*.
  shared_ptr<T> p(u)    p assumes ownership from the unique_ptr u; makes u null
  shared_ptr<T> p(q, d) p assumes ownership for the object to which the built-in
                        pointer q points. q must be convertible to T* (§ 4.11.2,
                        p. 161). p will use the callable object d (§ 10.3.2, p.
                        388) in place of delete to free q.
  shared_ptr<T> p(p2, d) p is a copy of the shared_ptr p2 as described in
                         Table 12.2 except that p uses the callable object d in
                         place of delete.
  p.reset()
  p.reset(q)
  p.reset(q, d)
  */

  /* ... and Don’t Use get to Initialize or Assign Another Smart Pointer */
  {
    shared_ptr<int> p(new int(42));  // reference count is 1
    int *q = p.get();
    // ok: but don’t use q in any way that might delete its pointer
    // The code that uses the return from get must not delete that pointer
    {  // new block
      // undefined: two independent shared_ptrs point to the same memory
      shared_ptr<int>(q);
    }  // block ends, q is destroyed, and the memory to which q points is freed
    int foo = *p;  // undefined; the memory to which p points was freed

    /*
    both p and q point to the same memory. Because they were created
    independently from each other, each has a reference count of 1. When the
    block in which q was defined ends, q is destroyed. Destroying q frees the
    memory to which q points. That makes p into a dangling pointer, meaning that
    what happens when we attempt to use p is undefined. Moreover, when p is
    destroyed, the pointer to that memory will be deleted a second time.
    */
  }
  return 0;
}