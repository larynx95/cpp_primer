/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Section 2.1 Primitive Built-in Types
Section 2.2 Variables
Section 2.3 Compound Types
******************************************************************************/

#include <iostream>

int main() {
  /********************************************************
  2.3.1. References
  (Exercises 2.15 ~ 2.16)
  TODO: What is the difference bw reference and pointer?
  TODO: What is the usefulness of reference?
  a. reference
     alias, alternative name for an object
     Reference is not an object.
     Once defined, the object that it refers to can't be changed.
     declared, and initialized simultaneously
     A reference is not an object.
     Instead, a reference is just another name for an already existing object
     Reference can't be NULL.
  b. pointer
     declared, and can be used later
     compound type that “points to” another type
     It can point to an object.
     It can point to the location just immediately past the end of an object.
     It can be a null pointer, indicating that it is not bound to any object.
     It can be invalid; values other than the preceding three are invalid.
  ********************************************************/

  {
    int i = 1024;
    int &r = i;  // r refers to (is another name for) i
    // int &r2;        // error: a reference must be initialized

    r = 2;       // assigns 2 to the object to which r refers, i.e., to i
    int ii = r;  // same as ii = i
    std::cout << "ii is " << ii << " and r is " << r << std::endl;

    // ok: r3 is bound to the object to which
    // i is bound, i.e., to i
    int &r3 = i;
    // initializes i from the value in the object to which i is bound
    int j = i;  // ok: initializes j to the same value as i
  }

  {
    int i1 = 1024, i2 = 2048;  // i and i2 are both ints
    int &r1 = i1, r2 = i2;     // r is a reference bound to i; r2 is an int
    int i3 = 1024, &ri = i3;   // i3 is an int; ri is a reference bound to i3
    int &r3 = i3, &r4 = i2;    // both r3 and r4 are references

    std::cout << "i1: " << i1 << std::endl;  // 1024
    std::cout << "i2: " << i2 << std::endl;  // 2048
    std::cout << "i3: " << i3 << std::endl;  // 1024

    std::cout << "r1: " << r1 << std::endl;  // 1024
    std::cout << "r2: " << r2 << std::endl;  // 2048
    std::cout << "r3: " << r3 << std::endl;  // 1024

    // int &refVal4 = 10;  // error: initializer must be an object
    double dval = 3.14;
    // int &refVal5 = dval;  // error: initializer must be an int object
  }

  /********************************************************
  2.3.2. Pointers
  (Exercises 2.18 ~ 22)

  TODO: How to decipher the pointer expression?
  https://cdecl.org
  spiral rule: http://c-faq.com/decl/spiral.anderson.html
  TODO: What are the differences
  between a pointer variable and a reference variable in C++?
  https://stackoverflow.com/questions/57483/what-are-the-differences-between-a-pointer-variable-and-a-reference-variable-in

  The value stored in apointer can be in one of four states:
    a. It can point to an object.
    b. It can point to the location just immediately past the end of an object.
    c. It can be a null pointer.
    d. It can be invalid; values other than the preceding threee are invalid.

  void* pointer
    - can't be dereferenced
  ********************************************************/

  {
    // using a pointer to access an object
    int *ip, *ipp;    // both ip and ip1 are pointers to int
    double dv, *dpp;  // dp1 is a pointer to double; dv is a double
    double dval = 3.14;

    int ival_b = 42;
    int *ip1 = &ival_b;  // p holds the address of ival; p is a pointer to ival
    std::cout << *ip1 << std::endl;  // dereferencing

    double *dp1 = &dval;  // ok: initializer is the address of a double
    double *dp2 = dp1;    // ok: initializer is a pointer to double
    // int *pi = dp1;        // error: types of pi and pd differ
    // pi = &dval;  // error: assigning the address of a dbl to a ptr to int
  }

  // null pointer
  // https://en.cppreference.com/w/cpp/language/nullptr

  {
    int *p1ip3 = nullptr;  // equivalent to int *ip3 = 0;
    int *p2 = 0;     // directly initializes ip4 from the literal constant 0
                     // must #include cstdlib
    int *p3 = NULL;  // equivalent to int *ip5 = 0;

    // void* pointer
    double obj = 3.14, *dp1 = &obj;
    // ok: void* can hold the address value of any data pointer type
    void *dp2 = &obj;  // obj can be an object of any type
    dp2 = dp1;         // dp2 can hold a pointer to any type
  }

  // void pointer
  {
    int num1 = 10;
    float num2 = 3.5f;
    char c1 = 'a';
    int *numPtr1 = &num1;
    char *cp1 = &c1;

    void *vp1;  // void pointer declared

    // ok with different types to void ptr
    vp1 = numPtr1;
    vp1 = cp1;

    // std::cout << "*ptr: " << *ptr << std::endl;
    std::cout << "*ptr: " << *(char *)vp1 << std::endl;

    // Error with void ptr to different types
    // numPtr1 = vp1;
    // cp1 = vp1;

    vp1 = &num1;
    // printf("%d\n", *vp1);  // error
    printf("%d\n", *(int *)vp1);

    vp1 = &num2;
    // printf("%f\n", *vp1);  // error
    printf("%f\n", *(float *)vp1);

    vp1 = &c1;
    // printf("%c\n", *vp1);  // error
    printf("%c\n", *(char *)vp1);
  }

  /********************************************************
  2.3.3 Understanding Compound Type Declarations
  (Exercises 2.25)
  ********************************************************/

  // defining multiple variables
  {
    int *p, v;     // ip6 is ptr, iv6 is int
    int *p1, *p2;  // p7 and p8 are ptr
  }

  // *   pointer
  // **  pointer to pointer
  // *** pointer to pointer to pointer
  {
    int i = 1024;
    int *p = &i;
    int **pp = &p;

    std::cout << "i: " << i << std::endl;
    std::cout << "*p: " << *p << std::endl;
    std::cout << "**pp: " << **pp << std::endl;
  }

  // reference to pointer
  {
    int i = 42;
    int *p;
    int *&r = p;  // TODO: r is a reference to the pointer p
    r = &i;       // r refers to a pointer, assigning &i to r makes p point to i
    *r = 0;       // dereferencing r yields i
  }

  return 0;
}

/*
Section 2.4 const Qualifier
Section 2.5 Dealing with Types
Section 2.6 Defining Our Own Data Structures
*/
