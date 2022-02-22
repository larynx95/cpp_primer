/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.32: In the program onpage 354 would it be legal to write the call
to insert as follows? If not, why not?

iter = vi.insert(iter, *iter++);

Answer:
It is not legal. The order of evaluation of the arguments in function insert is
undefined, so that if the second argument is evalated first, then the program
logic will be wrong.

*/
