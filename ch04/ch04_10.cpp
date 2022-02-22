/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 4. Expressions

Section 4.1 Fundamentals
Section 4.2 Arithmetic Operators
Section 4.3 Logical and Relational Operators
Section 4.4 Assignment Operators
Section 4.5 Increment and Decrement Operators
Section 4.6 The Member Access Operators
Section 4.7 The Conditional Operator
Section 4.8 The Bitwise Operators
Section 4.9 The sizeof Operator
Section 4.10 Comma Operator (Exercises 4.31 ~ 4.33)
******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  // comma operator in for-loop
  {
    vector<int> ivec = {0, 1, 1, 3, 4};
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt) {
      ivec[ix] = cnt;
      cout << "ix, cnt: " << ix << ", " << cnt << endl;
    }

    for (auto it = ivec.begin(); it != ivec.end(); it++) {
      cout << *it << " ";
    }
  }

  return 0;
}

/*
Section 4.11 Type Conversions
Section 4.12 Operator Precedence Table
*/