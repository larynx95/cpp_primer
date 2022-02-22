/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.6: Explain the differences between a parameter, a local variable,
and a local static variable. Give an example of a function in which each
might be useful.

Answer:
A local variable is a variable defined inside the function scope.

The scope of a local variable is the function body.
The lifetime of the ordinary local variable (nonstatic) starts when control
passes through the variable's definition, and ends when control passes through
the end of the block in which the variable is defined. It is initialized if its
definition contains an initializer, otherwise, it is default initialized. A
parameter is also a local variable, but the definition is in the parameter list
of the function.

The scope of a parameter is the same as local variable, which is the function
body. The lifetime of the parameter starts when the function begins, and ends
when the function terminates. It is initialized by the arguments passed to the
function. A local static variable is a local variable that defined with static
keyword. It has a lifetime much longer than usual local variable.

The scope of a local static variable is the same as local variable, which is the
function body. The lifetime of the local static varible starts when the first
time control passes through the variable's definition, and ends when the program
terminates. It is initialized if its definition contains an initializer,
otherwise, it is value initialized. For example,

int foo(int param) {
  int lv;
  static int lsv = 1;
  lv = param + lsv;
  ++lsv;
  return lv;
}
every time the function foo is called, it will add how many times it has been
called to the argument and return the sum.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch6/6.6.md

*/

#include <iostream>

int main() {
  //
  return 0;
}