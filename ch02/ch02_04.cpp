/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Section 2.1 Primitive Built-in Types
Section 2.2 Variables
Section 2.3 Compound Types
Section 2.4 const Qualifier
******************************************************************************/

#include <iostream>

int get_size() { return 100; }
constexpr int size() { return 100; }

int main() {
  /********************************************************
  2.4 const Qualifier
  (Exercises 2.26)
  ********************************************************/

  // const variable is immutable
  {
    const int bufSize = 512;  // input buffer size
    // bufSize = 512; // error: attempt to write to const object
  }

  // initializers for const variable
  {
    const int i = get_size();  // ok: initalized at run time
    const int j = 42;          // ok: initilaized at compile time
    // const int k;            // error: k is uninitialized const
  }

  // initialization and const
  {
    int i = 42;
    const int ci = i;  // ok: the value in i is copied into ci
    int j = ci;        // ok: the value in ci is copied into j

    // Although ci is a const int, the value in ci is an int.
    // The constness of ci matters only for operations that might change ci.
    // When we copy ci to initialize j,
    // we don’t care that ci is a const.
    // Copying an object doesn’t change that object.
    // Once the copy is made,
    // the new object has no further access to the original object.
  }

  // using const variable in multiple files (by extern keyword)
  {
      // const, extern
      // const object is local to a file
      // It is exist only in a file.
      // If we want to use const variable in multiple files,
      // we should use extern keyword.

      // file_1.cc
      // defines and initializes a const that is accessible to other files
      //     extern const int bufSize = fcn();

      // file_1.h
      //     extern const int bufSize;
      // same bufSize as defined in file_1.cc
  }

  /********************************************************
  2.4.1. Reference to const (a.k.a. const reference)
  ********************************************************/

  // reference to an object of a const type
  {
    const int ci = 1024;
    const int &r1 = ci;  // ok: both reference and underlying object are const
    // r1 = 42;             // error: r1 is a reference to const
    // int &r2 = ci;       // error: non const reference to a const object
  }

  // Initialization and References to const
  // Reference ruls:
  //   "The type of a reference must match
  //    the type of the object to which it referes."

  // two exceptions:
  // a. The first exception is that
  //    we can initialize a reference to const from any expression
  //    that can be converted to the type of the reference.
  //    In particular, we can bind a reference to const to
  //    a nonconst object, a literal, or a more general expression
  {
    int i = 42;
    const int &r2 = i;       // we can bind a const int& to a plain int object
    const int &r3 = 42;      // ok: r1 is a reference to const
    const int &r4 = r2 * 2;  // ok: r3 is a reference to const
    // int &r4 = r2 * 2;     // error: r4 is a plain, non const reference

    double dval = 3.14;                      // dval is double type
    const int &ri = dval;                    // MISMATCH! but no Error!
    std::cout << "ri: " << ri << std::endl;  // ri: 3, loss of data

    // TODO: What happened here?
    // We knows that a reference can't refer to an object with different type.
    // int & ref = dval;   // Error, type mismatch
    // But reference to const allow it here!
    // Explanation:
    // A const reference refers to an object with different type
    // vis temporary object.

    const int temp = dval;  // create a temporary const int from the double
    const int &ri2 = temp;  // bind ri to that temporary
    std::cout << "temp: " << temp << std::endl;  // temp: 3
  }

  // A Reference to const May Refer to an Object That Is Not const
  {
    // It is important to realize that a reference to const
    // restricts only what we can do through that reference.

    int i = 42;
    int &r1 = i;        // r1 bound to i
    const int &r2 = i;  // r2 also bound to i; but cannot be used to change i
    r1 = 0;             // r1 is not const; i is now 0
    // r2 = 0;          // error: r2 is a reference to const
  }

  /********************************************************
  2.4.2. Pointers and const
  ********************************************************/

  // pointer to const
  // We may store the address of a const object only in a pointer to const.
  // But pointer to const can point to both cons and non-const.

  // As with references,
  // we can define pointers that point to either const or nonconst types.
  // Like a reference to const,
  // a pointer to const may not be used to change the object
  // to which the pointer points.
  // We may store the address of a const object only in a pointer to const

  {
    /* The pointer cptr points to const.
                pointer      value
      ----------------------------------
      name:     cptr         pi (const)
      value:    0x02*        3.14
      address:  0x01         0x02
    */

    const double d = 3.33;  // const double, immutable
    const double *dp = &d;  // pointer to const double, target is immutable

    const double pi = 3.14;  // pi is const; its value may not be changed
    // double *ptr = &pi;    // error: ptr is a plain pointer

    const double *cptr = &pi;  // ok: cptr may point to a double that is const
    // *cptr = 42;             // error: cannot assign to *cptr

    /* Now cptr points to non-const.
                pointer      value
      ----------------------------------
      name:     cptr         dval (non-const)
      value:    0x08*        3.14
      address:  0x01         0x08
    */

    double dval = 3.14;  // dval is a double; its value can be changed
    cptr = &dval;        // ok: but can't change dval through cptr
  }

  // const pointer (not pointer to const)
  {
    /*
    const int *ptr : pointer to const int type (p2c)
    int *const ptr : const pointer to int type (cp)

                pointer to const   const pointer
    ----------------------------------------------------
    target      immutable          mutable by dereferencing
    value       mutable            immutable
                reassigned(O)      reassigned(X)
    constness   target             pointer variable

    const double * const ptr = ...
    -----          ---------
    (1)            (2)
    (1): constness of target object
    (2): constness of pointer variable

    const pointer
      Unlike reference, pointer is object.
      Hence a pointer itself can be const.
      That is called "const pointer".
      Reference is not object,
      so "const referene" is not correct word.
      - must be initialized
      - once initialized, the value may not be changed
      - The address that it holds is constant.

    Constant pointer vs Pointer to constant [duplicate]
    https://stackoverflow.com/questions/21476869/constant-pointer-vs-pointer-to-constant
    - must be initialized
    - not pointer-to type
    - pointer that is const
 */
    const double pi = 3.14159;
    int errNumb = 0;
    int *const curErr = &errNumb;   // curErr will always point to errNumb
    *curErr = 100;                  // target value of const pointer is mutable
    const double *const pip = &pi;  // pip is a const pointer to a const object

    // *pip = 2.72;                 // error: pip is a pointer to const
    // if the object to which curErr points (i.e., errNumb) is nonzero
    if (*curErr) {
      *curErr = 0;
      // ok: reset the value of the object to which curErr is bound
      // TODO: What does this mean?
    }
  }

  /********************************************************
  2.4.3. Top-Level const
  (Excercises 2.27 ~ 29)
  *********************************************************/

  // TODO: Top-Level const (ex30)
  // https://stackoverflow.com/questions/7914444/what-are-top-level-const-qualifiers

  {
    int i = 0;
    int *const p1 = &i;  // we can't change the value of p1; const is top-level
    const int ci3 = 42;  // we cannot change ci3; const is top-level
    const int *p2 = &ci3;  // we can change p2; const is low-level
    const int *const p3 =
        p2;              // right-most const is top-level, left-most is not
    const int &r = ci3;  // const in reference types is always low-level

    i = ci3;  // ok: copying the value of ci; top-level const in ci3 is ignored
    p2 = p3;  // ok: pointed-to type matches; top-level const in p3 is ignored

    /* http://www.cplusplus.com/forum/general/212966/ */
    i = 0;
    int x = 100;

    int *ptr_to_int = &i;
    // non-const pointer to non-const int
    // non-const at top-level, non-const at low-level
    ptr_to_int = &x;  // ptr_to_int can be modified

    const int *ptr_to_const_int = &i;
    // non-const pointer to const int
    // non-const at top-level, const at low-level
    ptr_to_const_int = &x;  // ptr_to_const_int can be modified

    int *const const_ptr_to_int = &i;
    // const pointer to non-const int
    // const at top-level, non-const at low-level
    // const_ptr_to_int = &x;  // error, can't be modified

    const int *const const_ptr_to_const_int = &i;
    // const pointer to const int
    // const at top-level, const at low-level
  }

  /********************************************************
  2.4.4. constexpr and Constant Expressions
  *********************************************************/

  // constexpr is expression whose value cannot change and that can be evaluated
  // at compile time. A literal is a constant expression. A const object that is
  // initialized from a constant expression is also a constant expression.

  // constant expression
  // - expression whose value can't change
  // - expression whose value can be evaluated at compile time
  // - literals
  // - const objects initialized from constant expression

  // constness vs. constrexpr-ness
  // constness: logically constant, value can't be changed
  // constexpr-ness: value is fixed at compile time

  // TODO: Why should we use constexpr?
  // - We can get the result in compile tile.
  // - Not all expression with "const" keyword is not constexpr.
  // - We can ask the compiler to verify that a variable is constexpr.

  // constexpr
  {
    const int max_files1 = 20;          // (O) literal
    const int limit1 = max_files1 + 1;  // (O) initialized from constexpr
    int staff_size1 = 27;               // (X) plain int, not const int
    const int sz1 = get_size();         // (X) value is not known until runtime
  }

  // constexpr variables
  {
    constexpr int mf = 20;          // (O) literal
    constexpr int limit2 = mf + 1;  // (O) mf + 1 is constexpr
    constexpr int sz = size();      // (O) size() fx is constexpr
  }

  // Pointers and constexpr
  {
    // the constexpr specifier applies to the pointer,
    // not the type to which the pointer points
    // constexpr poiner may point to a const or non-const type.

    const int x = 100;
    const int y = 200;
    const int *p = nullptr;      // p is a pointer to a const int
    constexpr int *q = nullptr;  // q is a const pointer to int
    p = &x;                      // (O) this is possible
    // q = &x;                      // (X)
  }

  // const pointer vs. constexpr pointer
  {
    constexpr int *np = nullptr;  // const pointer to int, value is null
    int j = 0;
    constexpr int i = 42;  // type of i is const int

    // TODO:??
    // i and j must be defined outside any function
    constexpr const int *p = &i;  // p is a constant pointer to the const
    constexpr int *p1 = &j;       // p1 is a constant pointer to the
  }

  return 0;
}

/*
Section 2.5 Dealing with Types
Section 2.6 Defining Our Own Data Structures
*/
