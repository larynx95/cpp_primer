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
Section 4.10 Comma Operator
Section 4.11 Type Conversions
******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  // When Implicit Conversions Occur
  {
    // the compiler might warn about loss of precision
    int ival = 3.541 + 3;
    cout << "ival: " << ival << endl;  // 6

    /* automatic conversion
    - In most expressions, values of integral types smaller than int
      are first promoted to an appropriate larger integral type.
    - In conditions, nonbool expressions are converted to bool.
    - In initializations,
      the initializer is converted to the type of the variable;
      in assignments, the right-hand operand is converted
      to the type of the left-hand.
    - In arithmetic and relational expressions with operands of mixed types,
      the types are converted to a common type.
    - Conversions also happen during function calls. (Chapter 6)
    */
  }

  /********************************************************
  4.11.1. The Arithmetic Conversions (Exercises 4.34 ~ 35)
  ********************************************************/

  // Integral Promotions

  // Operands of Unsigned Type

  // Understanding the Arithmetic Conversions

  /********************************************************
  4.11.2. Other Implicit Conversions
  ********************************************************/

  // array to pointer conversions
  {
  int ia[10];    // array of ten ints
  int *ip = ia;  // convert ia to a pointer to the first element
  }

  // pointer conversions
  {
    const char *cp = "Hello";
    // if(cp) /* ... */       // true if the pointer cp is not zero
    // while (*cp) /* ... */  // true if *cp is not the null character
  }

  // conversion to const 
  {
    int i;
    const int &j = i;   // convert a nonconst to a reference to const int
    const int *p = &i;  // convert address of a nonconst to the address of a const
    // int &r = j, *q = p;
    // error: conversion from const to nonconst not allowed
  }

  // conversions defined by class types
  {
    string s, t = "a value";  
    // while (cin >> s) ...
  }

  /********************************************************
  4.11.3. Explicit Conversions (Exercises 4.36 ~ 4.37)
  ********************************************************/

  // Named casts 
  // - static_cast
  // - dynamic_cast
  // - const_cast
  // - reinterpret_cast

  // static_cast
  {
    // cast used to force floating-point division
    int i = 3; 
    int j = 10;
    double slope = static_cast<double>(j) / i;
    cout << "slope: " << slope << endl; // 3.33333

  }

  // const_cast - cast away the const
  {
    const char *pc; 
    char *p = const_cast<char*>(pc);

    const char *cp; 
    static_cast<string>(cp);  // string literal --> string 
    // const_cast<string>(cp);   // error,
  }

  // reinterpret_cast
  {
    int iv = 100;
    int *ip = &iv; 
    char *cp = reinterpret_cast<char*>(ip);
    cout << "ip: " << ip << endl;    // 0xffffcb74
    cout << "*ip: " << *ip << endl;  // 100
    cout << "cp: " << cp << endl;    // d, TODO: ?
    cout << "*cp: " << *cp << endl;  // d
  }

  // Old-Style Casts
  {
    // Depending on the types involved, 
    // an old-style cast has the same behavior as a const_cast, 
    // a static_cast, or a reinterpret_cast. 

    int ival = 100;
    int * ip = &ival;
    char *cp = (char*) ip; // ip is a pointer to int 
    cout << "ival: " << ival << endl;
    cout << "*ip: " << *ip << endl;  // 100
    cout << "*cp: " << *cp << endl;  // d
  }

  return 0;
}

/*
Section 4.12 Operator Precedence Table
*/