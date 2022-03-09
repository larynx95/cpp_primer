/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 12. Dynamic Memory

Exercise 12.4:
In our check function
we didn’t check whether i was greater than zero.
Why is it okay to omit that check?
************************************************/

/*
Answer:
Because i, or data->size(), would never be less than 0: its type is
std::vector<std::string>::size_type, which is an unsigned integer type (usually
size_t).
*/