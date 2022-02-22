/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 8. The IO Library

Exercise 8.3: What causes the following while to terminate?

while (cin >> i) // ...

Answer:
https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch8/8.3.md

The condition of a stream is equivalent to !fail(), which means set either
failbit or badbit will terminate the loop. For example, errors list below will
terminate the loop:

- System-level failure. (Set the badbit) Such as an unrecoverable r/w error.
- Recoverable error. (Set the failbit) Such as reading a character when
numeric data expected.
- Reaching end-of-file. (Set both the eofbit and failbit)




*/