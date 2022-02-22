/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Section 2.1 Primitive Built-in Types
Section 2.2 Variables
Section 2.3 Compound Types
Section 2.4 const Qualifier
Section 2.5 Dealing with Types
******************************************************************************/

#include <iostream>

#include "Sales_item.h"

typedef double wages;    // wages is a synonym for double
typedef wages base, *p;  // base is a synonym for double, p for double*
using SI = Sales_item;   // SI is a synonym for Sales_item

int main() {
  /********************************************************
  2.5.1. Type Aliases, Pointers, const , and Type Aliases
  ********************************************************/

  // type alias
  {
    wages hourly, weekly;  // same as double hourly, weekly;
    SI item;               // same as Sales_item item

    // We can substitute "wages" with "double", and it works.
    // But we should be careful when we're using typedef.
    // Simple substitution does not work at all.

    typedef char *pstring;   // pstring is pointer to char
    const pstring cstr = 0;  // TODO: constant pointer to char
    const pstring *ps;       // TODO: pointer to a constant pointer to char

    // const char *cstr = 0;
    // TODO: wrong interpretation of const pstring cstr
    //       This rewrite declares cstr as a pointer to const char
    //       rather than as a const pointer to char.

    // wrong interpretation
    // a. const pstring cstr    : constant pointer to char (O)
    //    !=  const char * cstr : pointer to cons char     (x)
    // b. const pstring *ps     : pointer to constant pointer to char (O)
    //    !=  const char ** ps  : pointer to pointer to const char    (X)
  }

  /********************************************************
  2.5.2. The auto Type Specifier
  (Exercises 2.33 ~ 35)
  ********************************************************/

  // type deducing
  {
    int val1 = 10, val2 = 10;
    auto item = val1 + val2;  // item initialized to the result of val1 + val2

    auto i1 = 0, *p1 = &i1;  // ok: i1 is int and p1 is a pointer to int
    // auto sz1 = 0, pi = 3.14;  // error: inconsistent types for sz1 and pi
  }

  // compound types, const, and auto
  {
    int i = 0, &r = i;
    auto a = r;  // a is an int (r is an alias for i, which has type int)
  }

  // auto ordinarily ignores top-level const
  {
    int i = 0;
    const int ci = i, &cr = ci;
    auto b = ci;   // b is an int (top-level const in ci is dropped)
    auto c = cr;   // c is an int (cr: alias for ci whose const is top-level)
    auto d = &i;   // d is an int*(& of an int object is int*)
    auto e = &ci;  // e is const int*(& of a const object is low-level const)

    // if we want the deduced type to have a top-level const, go explicit
    const auto f = ci;  // deduced type of ci is int; f has type const int

    auto &g = ci;  // g is a const int& that is bound to ci
    // auto &h = 42;        // error: we can't bind a plain reference to a
    // literal
    const auto &j = 42;  // ok: we can bind a const reference to a literal

    auto k = ci, &l = i;     // k is int; l is int&
    auto &m = ci, *p = &ci;  // m is a const int&;p is a pointer to const int
    // error: type deduced from i is int; type deduced from &ci is const int
    // auto &n = i, *p2 = &ci;
  }

  /********************************************************
  2.5.3. The decltype Type Specifier
  (Exercises 2.36 ~ 38)
  ********************************************************/

  // decltype(f()) sum = x;  // sum has whatever type f returns

  // decltype
  {
    const int ci = 0, &cj = ci;
    decltype(ci) x = 0;  // x has type `const int`
    decltype(cj) y = x;  // y has type `const int&` and is bound to x
    // decltype(cj) z;   // error: z is a reference and must be initialized

    std::cout << "ci: " << ci << std::endl;  // ci: 0
    std::cout << "cj: " << cj << std::endl;  // cj: 0
  }

  // decltype and References
  {
    // decltype of an expression can be a reference type
    int i = 42, *p = &i, &r = i;
    decltype(r + 0) b;
    // ok: addition yields an int; b is an (uninitialized) int
    // decltype(*p) c3;  // error: c is int& and must be initialized

    // TODO: decltype of a parenthesized variable is always a reference
    // decltype((i)) d;  // error: d is int& and must be initialized
    decltype(i) e;  // ok: e is an (uninitialized) int

    // When we apply decltype to a variable without any parentheses,
    // we get the type of that variable.
    // If we wrap the variable’s name in one or more sets of parentheses,
    // the compiler will evaluate the operand as an expression.
    // A variable is an expression
    // that can be the left-hand side of an assignment.
    // As a result, decltype on such an expression yields a reference
  }

  return 0;
}

/*
Section 2.6 Defining Our Own Data Structures
*/
