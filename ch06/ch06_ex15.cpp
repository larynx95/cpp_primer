/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.15: Explain the rationale for the type of each of find_char’s
parameters In particular, why is s a reference to const but occurs is a
plain reference? Why are these parameters references, but the char
parameter c is not? What would happen if we made s a plain reference?
What if we made occurs a reference to const?

Answer:
The function prototype is

string::size_type find_char(const string &s,
                            char c,
                            string::size_type &occurs)

s and occurs are both referecnes to avoid copy.

s is const because it isn't changed inside function and a string literal can be
used here. occurs is plain reference beacuse it is used to pass information
(changed inside function).

c is nonreference because copy a char is very cheap. It's fine to make it a
const reference but not plain reference, because we don't want to accidentally
change c inside function, and we may want to pass a char literal to the
function.

If occurs is made a reference to const, then we cannot get how many times the
character c occurred in string s.

*/