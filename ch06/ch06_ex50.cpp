/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.50: Given the declarations for f from page 242, list the viable
functions, if any for each of the following calls. Indicate which function is
the best match, or if the call is illegal whether there is no match or why the
call is ambiguous.

(a) f(2.56, 42)

(b) f(42)

(c) f(42, 0)

(d) f(2.56, 3.14)

Answer:
(a) f(2.56, 42) is illegal. The call is ambiguous, because either f(int, int) or
f(double, double) is a better match than the other on one of the arguments to
the call.

(b) f(42) has a best match function f(int). (c) f(42, 0) has a best match
function f(int, int). (d) f(2.56, 3.14) has a best match function f(double,
double).


*/
