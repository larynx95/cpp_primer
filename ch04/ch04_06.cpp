/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 4. Expressions

Section 4.1 Fundamentals
Section 4.2 Arithmetic Operators
Section 4.3 Logical and Relational Operators
Section 4.4 Assignment Operators
Section 4.5 Increment and Decrement Operators
Section 4.6 The Member Access Operators (Exercises 4.6)
******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  // dot & arrow operators
  {
    string s1 = "a string", *p = &s1;
    auto n = s1.size();  // run the size member of the string s1
    n = (*p).size();     // run size on the object to which p points
    n = p->size();       // equivalent to (*p).size()
    // run the size member of p, then dereference the result!
    // *p.size();  // error: p is a pointer and has no member named size
    cout << "(*p).size() is " << (*p).size() << endl;  // 8
  }

  return 0;
}

/*
Section 4.7 The Conditional Operator
Section 4.8 The Bitwise Operators
Section 4.9 The sizeof Operator
Section 4.10 Comma Operator
Section 4.11 Type Conversions
Section 4.12 Operator Precedence Table
*/