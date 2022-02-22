/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.29: List some of the drawbacks of using an array instead of a
vector.

Answer:
- The size of the array is fixed and must be known when defined.
- Character array needs to leave space for null character at the end.
- Arrays can not be copied or assigned as a whole.
- Array can not be constructed with the same values
  like the constructor of vector when defined.
- The size of array must be calculated when using
  (sometimes cannot be calculated at all) instead of calling a size() method.
******************************************************************************/
