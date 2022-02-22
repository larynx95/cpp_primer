/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.46: Would it be possible to define isShorter as a constexpr?
If so, do so. If not, explain why not.

Answer:
No, a constexpr function may only contains statements that generate no actions
at run time, but the member method size() must be called at run time, thus the
function can not be a constexpr function.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch6/6.46.md

*/
