/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.16: The following function, although legal, is less useful than it
might be. Identify and correct the limitation on this function:

bool is_empty(string& s) { return s.empty(); }

Answer:
The parameter of the function should be const string &s. So that we can pass
string literals or const strings to the function.
*/