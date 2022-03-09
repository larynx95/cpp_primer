/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 12. Dynamic Memory

Exercise 12.5:
We did not make the constructor
that takes an initializer_list explicit (§ 7.5.4, p. 296).
Discuss the pros and cons of this design choice.
************************************************/

/*
Answer:
The constructor takes an initializer_list as an argument, making the
constructor explicit would not allow implicit conversion from a any convertible
class type to an initializer_list. It would also disallow the assignment
operator.
*/