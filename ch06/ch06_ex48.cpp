/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.48: Explain what this loop does and whether it is a good use of
assert:

string s;
while (cin >> s && s != sought) { } // empty body
assert(cin);

Answer:
The loop are used to keep reading string from the input until sought found. It
is a bad idea to use assert check whether cin is in an error state. Because when
the program compiled with NDEBUG preprocessor variable, the statement would not
be excuted.

*/
