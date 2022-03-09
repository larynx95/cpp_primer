/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 12. Dynamic Memory

Exercise 12.10:
Explain whether the following call to the process function
defined on page 464 is correct.
If not, how would you correct the call?

shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));

************************************************/

/*
Answer:
The code is correct. p is a shared pointer that can point to an int. It is
initialized (using new) with the value 42. We explicitly create a copy of p and
pass it to process as an argument. As a result, p's reference counter is
incremented to 2. When process finishes the copy is destroyed and p's counter
is decremented to 1. The code has the same effect as passing p to process by
value:
*/