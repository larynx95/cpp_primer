/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.6: What, if any, are the differences between the following
definitions:

int month = 9, day = 7;
int month = 09, day = 07;

Answer:
int month = 09;
09 is octal number

*/

#include <iostream>

int main() {
  int month = 9, day = 7;  // OK
  int month1 = 07;         // 09 can't be octal number
  int day1 = 07;
  // Error: the digit of octal integral literal should in range 0~7

  return 0;
}