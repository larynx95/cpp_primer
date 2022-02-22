/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.24: Explain the behavior of the following function. If there are
problems in the code, explain what they are and how you might fix them.

void print(const int ia[10])
{
  for (size_t i = 0; i != 10; ++i)
  cout << ia[i] << endl;
}

Answer:
The function prototype is the same as void print(const int *ia), which means we
can pass any pointer to int to the function, not only an array of ten ints. This
will lead to an error. We can change the parameter to a reference to array:

void print(const int (&ia)[10]) { // ... }

*/