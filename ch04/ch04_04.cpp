/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 4. Expressions

Section 4.1 Fundamentals
Section 4.2 Arithmetic Operators
Section 4.3 Logical and Relational Operators
Section 4.4 Assignment Operators (Exercises 4.13 ~ 4.16)
******************************************************************************/

#include <iostream>
using namespace std;

int main() {
  // assignment is right-associative
  {
    int ival, jval;
    ival = jval = 0;  // ok: each assigned 0
    ival = {5};
    cout << "ival is " << ival << endl;
  }

  // Assignment Has Low Precedence
  {
    int i;
    // a better way to write our loop---what the condition does is now clearer
    while ((i = get_value()) != 42) {
      // do something ...
    }
  }

  // Beware of Confusing Equality and Assignment Operators

  // Compound Assignment Operators

  return 0;
}

/*
Section 4.5 Increment and Decrement Operators
Section 4.6 The Member Access Operators
Section 4.7 The Conditional Operator
Section 4.8 The Bitwise Operators
Section 4.9 The sizeof Operator
Section 4.10 Comma Operator
Section 4.11 Type Conversions
Section 4.12 Operator Precedence Table
*/