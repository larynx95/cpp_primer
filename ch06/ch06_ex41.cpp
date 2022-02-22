/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.41: Which, if any, of the following calls are illegal? Why? Which,
if any, are legal but unlikely to match the programmer’s intent? Why?
Click here to view code image
char *init(int ht, int wd = 80, char bckgrnd = ' ');
(a) init();
(b) init(24,10);
(c) init(14, '*');

Answer:
(a) init(); is illegal, must have at least one argument.

(b) init(24, 10); is legeal.

(c) init(14, '*'); is legal, but unlikely to match the programer's intent.
Because the character * will be promoted to int and match wd.

*/

#include <iostream>

int main() {
  //
  return 0;
}