/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 12. Dynamic Memory

Exercise 12.13:
What happens if we execute the following code?

auto sp = make_shared<int>();
auto p = sp.get();
delete p;

************************************************/

/*
Answer:
sp's memory will be deleted, leaving sp as a dangling pointer. Furthermore,
when sp goes out of scope the deconstructor will attempt to free its memory
again, causing an error (corruption of free memory).

*/