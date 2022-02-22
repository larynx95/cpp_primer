/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 4. Expressions

Section 4.1 Fundamentals
Section 4.2 Arithmetic Operators
Section 4.3 Logical and Relational Operators
Section 4.4 Assignment Operators
Section 4.5 Increment and Decrement Operators (Exercises 4.17 ` 4.19)
******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Combining Dereference and Increment in a Single Expression
  {
    vector<int> v = {1, 2, 3, 4, -12, 5, 6, 7, 8, 9};
    auto pbeg = v.begin();
    // print elements up to the first negative value
    while (pbeg != v.end() && *pbeg >= 0)
      cout << *pbeg++ << endl;  // print the current value and advance pbeg
  }

  // Remember That Operands Can Be Evaluated in Any Order
  {
    string str = "abcdefg";
    for (auto it = str.begin(); it != str.end() && !isspace(*it); ++it)
      *it = toupper(*it);  // capitalize the current character
  }

  // the behavior of the following loop is undefined!
  {
    /*
    auto ip = str.begin();
    while (ip != str.end() && !isspace(*ip))
      *ip = toupper(*ip++);
    */
    // error: this assignment is undefined
    // ip is changed within while loop
  }

  return 0;
}
/*
Section 4.6 The Member Access Operators
Section 4.7 The Conditional Operator
Section 4.8 The Bitwise Operators
Section 4.9 The sizeof Operator
Section 4.10 Comma Operator
Section 4.11 Type Conversions
Section 4.12 Operator Precedence Table
*/