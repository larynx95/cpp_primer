/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 4. Expressions

Section 4.1 Fundamentals
Section 4.2 Arithmetic Operators
Section 4.3 Logical and Relational Operators
Section 4.4 Assignment Operators
Section 4.5 Increment and Decrement Operators
Section 4.6 The Member Access Operators
Section 4.7 The Conditional Operator (Exercises 4.21 ~ 4.23)
******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Nesting Conditional Operations (ternary operator)
  {
    int grade = 70;
    string finalgrade = (grade < 60) ? "fail" : "pass";
    string nestingfinalgrade = (grade > 90)   ? "high pass"
                               : (grade < 60) ? "fail"
                                              : "pass";
  }

  // Using a Conditional Operator in an Output Expression
  {
    int grade = 70;

    // a.
    cout << ((grade < 60) ? "fail" : "pass") << endl;

    // The << operator returns cout,
    // which is tested as the condition for the conditional operator.

    // b-1.
    cout << (grade < 60) ? "fail" : "pass";

    // b-2. same as b-1
    cout << (grade < 60);  // prints 1 or 0
    cout ? "faile" : "pass";

    // c-1.
    // cout << grade < 60 ? "fail" : "pass";  // error

    // c-2. same as c-1
    // cout << grade;
    // cout < 60 ? "fail" : "pass";

    cout ? "fail" : "pass";
  }

  return 0;
}

/*
Section 4.8 The Bitwise Operators
Section 4.9 The sizeof Operator
Section 4.10 Comma Operator
Section 4.11 Type Conversions
Section 4.12 Operator Precedence Table
*/