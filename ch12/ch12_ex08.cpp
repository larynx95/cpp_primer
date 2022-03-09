/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 12. Dynamic Memory

Exercise 12.8:
Explain what if anything is wrong with the following function.

bool b() {
  int* p = new int;
  // ...
  return p;
}

************************************************/

/*
The code is legal. It checks if memory can be allocated for an int on the heap.
Though it returns a pointer, p, to the allocated block, the function's return
type is a bool, which means it will be true if allocation were successful and
false if not.  Thus, the pointer itself will go out of scope when the function
finishes and we will have a memory leak.

*/