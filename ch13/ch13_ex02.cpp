/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 13. Copy Control

Exercise 13.2:
Explain why the following declaration is illegal:

Sales_data::Sales_data(Sales_data rhs);

************************************************/

/*
Answer:
The parameter of the constructor should be a reference,
otherwise the call would never succeed.
To call the copy constructor,
we'd need to use the copy constructor to copy the argument,
but to copy the argument,
we'd need to call the copy constructor,
and so on indefinitely.
*/