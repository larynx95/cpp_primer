/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.37: What does the following program do?

const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while (*cp) {
  cout << *cp << endl;
  ++cp;
}

Answer:
Since there is no null character at the end, the program will print all the
characters in ca and continue print whatever in memeory until it find a null
character.

******************************************************************************/
