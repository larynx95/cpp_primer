/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 13. Copy Control

Exercise 13.3:
What happens when we copy a StrBlob? What about StrBlobPtrs?

************************************************/

/*
https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch13/13.3.md

When we copy a StrBlob, the underlying smart pointer is copyed.
But the vector to which the pointer pointed is not copyed, which means both
StrBlob objects will use the same vector. This may not be what we want.

When we copy a StrBlobPtr, the same thing happens as copying a StrBlob, but this
may be what we want.
*/