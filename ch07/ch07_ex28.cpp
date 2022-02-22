/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.28: What would happen in the previous exercise if the return
type of move, set, and display was Screen rather than Screen&?

Answer:
If then, every time we call move, set or display, the function will return a new
Screen object that is the copy of the original Screen object with the changes we
made, while the original Screen object keeps unchanged.

*/
