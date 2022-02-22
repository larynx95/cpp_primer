/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 8. The IO Library

Exercise 8.14: Why did we declare entry and nums as const auto &?

Answer:
By using reference, we avoid copy every object in vectors. By using const, we
avoid accidentally changing the values of elements in vectors.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch8/8.14.md
*/