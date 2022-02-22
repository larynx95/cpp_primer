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
Section 4.9 The sizeof Operator (Exercises 4.28 ~ 4.30)
******************************************************************************/

#include <iostream>
#include <vector>

#include "Sales_data.h"
using namespace std;

int main() {
  // sizeof operator: returns constant expression of type size_t
  {
    Sales_data data, *p;
    sizeof(Sales_data);  // size required to hold an object of type Sales_data
    sizeof data;         // size of data's type, i.e., sizeof(Sales_data)
    sizeof p;            // size of a pointer
    sizeof *p;  // size of the type to which p points, i.e., sizeof(Sales_data)
    sizeof data.revenue;  // size of the type of Sales_data's revenue member
    sizeof Sales_data::revenue;  // alternative way to get the size of revenue

    // The most interesting of these examples is sizeof *p.
    // First, because sizeof is right associative
    // and has the same precedence as *,
    // this expression groups right to left.
    // That is, it is equivalent to sizeof (*p).
    // (Associativity is order of parentheses.)
    // Second, because sizeof does not evaluate its operand,
    // it doesn’t matter that p is an invalid (i.e., uninitialized) pointer.
    // Dereferencing an invalid pointer as the operand to sizeof is safe
    // because the pointer is not actually used.
    // sizeof doesn’t need dereference the pointer to know
    // what type it will return.
  }

  // C++11 standard
  {
    /*
    - sizeof char or an expression of type char
      is guaranteed to be 1.

    - sizeof a reference type
      returns the size of an object of the referenced type.

    - sizeof a pointer returns the size needed hold a pointer.

    - sizeof a dereferenced pointer returns
      the size of an object of the type to which the pointer points;
      the pointer need not be valid.

    - sizeof an array is the size of the entire array.
      It is equivalent to taking the sizeof the element type
      times the number of elements in the array.
      Note that sizeof does not convert the array to a pointer.

    - TODO: sizeof a string or a vector returns
      only the size of the fixed part of these types;
      it does not return the size used by the object's elements.
    */

    char ch = 'a';
    char &cr = ch;
    char *cp = &ch;
    char arr[5] = "abcd";

    cout << "sizeof(ch): " << sizeof(ch) << endl;    // 1
    cout << "sizeof(cr): " << sizeof(cr) << endl;    // 1
    cout << "sizeof(cp): " << sizeof(cp) << endl;    // 8 (64 bits OS)
    cout << "sizeof(*cp): " << sizeof(*cp) << endl;  // 1
    cout << "sizeof *cp: " << sizeof *cp << endl;    // 1, TODO: ??
    cout << "sizeof(arr): " << sizeof(arr) << endl;  // 5

    vector<string> sr{"aaa", "bbb", "ccc"};
    cout << "sizeof(sr): " << sizeof(sr) << endl;       // 24
    cout << "sizeof(sr[0]: " << sizeof(sr[0]) << endl;  // 8
    cout << typeid(sr).name() << endl;                  // vector
    cout << typeid(sr[0]).name() << endl;               // string

    char *cr1[3] = {"aaaa", "bbbb", "cccc"};
    cout << "sizeof(cr1): " << sizeof(cr1) << endl;  // 24

    char crr[3][5] = {"aaaa", "bbbb", "cccc"};
    char(*cr2)[5] = crr;
    cout << "sizeof(cr2): " << sizeof(cr2) << endl;  // 8

    /*
    > g++
    vector<int>: St6vectorIiSaIiEE
    vector<char>: St6vectorIcSaIcEE
    vector<float>: St6vectorIfSaIfEE
    vector<string>: St6vectorISsSaISsEE
    vector<bool>: St6vectorIbSaIbEE
    */
  }

  return 0;
}

/*
Section 4.10 Comma Operator
Section 4.11 Type Conversions
Section 4.12 Operator Precedence Table
*/