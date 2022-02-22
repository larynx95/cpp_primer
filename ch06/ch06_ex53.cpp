/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.53: Explain the effect of the second declaration in each one of
the following sets of declarations. Indicate which, if any, are illegal.
(a) int calc(int&, int&);
int calc(const int&, const int&);
(b) int calc(char*, char*);
int calc(const char*, const char*);
(c) int calc(char*, char*);
int calc(char* const, char* const);

Answer:
(a)
int calc(int&, int&);
int calc(const int&, const int&);
// OK, overloaded function takes reference to `const`

(b)
int calc(char*, char*);
int calc(const char*, const char*);
// OK, overloaded function takes pointer to `const`

(c)
int calc(char*, char*);
int calc(char* const, char* const);
// Error, redeclare the same function, top-level `const` is ignored


*/
