/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 12. Dynamic Memory

Exercise 12.11:
What would happen if we called process as follows?

process(shared_ptr<int>(p.get()));

************************************************/

/*
Answer:
p would be a dangling pointer after process is finished, because the copy we
passed to process was independent of p, and as such, it also had a reference
counter of 1. When it went out of scope its object--also was pointed to
by p--was deleted.
*/