/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 12. Dynamic Memory

Exercise 12.12:
Using the declarations of p and sp explain each of the following calls
to process. If the call is legal, explain what it does. If the call is illegal,
explain why:

auto p = new int();
auto sp = make_shared<int>();
(a) process(sp);
(b) process(new int());
(c) process(p);
(d) process(shared_ptr<int>(p));

************************************************/

/*
Answer:
(a) Legal: passes a shared pointer to process. Note: sp is a nullptr
(b) Ilegal: cannot convert a raw pointer to shared_ptr<int>.
(c) Illegal: same as b, because p is a raw pointer.
(d) Legal: explicitly construct a shared pointer out of p. Note: the memory
        will be deleted and p will be a dangling pointer after process finishes.
*/