/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.3: Explain how whitespace characters are handled in the string
input operator and in the getline function.

Answer:
Whitespace characters include space, newline and tab.

The string input operator << will regard all three kinds of whitespace
characters as delimiter, so the string read from the operator will contain no
whitespace characters.

The getline function will regard only the newline character as delimiter, so the
string read from getline function will contain no newline character but may
contain space or tab.

******************************************************************************/
