/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 6. Functions

Section 6.1 Function Basics
Section 6.2 Argument Passing
******************************************************************************/

#include <cstdarg>  // for ellipsis parameter
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void reset(int *ip);
void resetRef(int &i);
void swapInt(int *a, int *b);
void swapIntRef(int &a, int &b);
bool isShorter(const string &s1, const string &s2);
string::size_type find_char(const string &s, char c, string::size_type &occurs);
bool is_sentence(const string &s);
void print1(const char *cp);
void print2(const int *beg, const int *end);
void print3(const int ia[], size_t size);
void print4(int (&arr)[10]);
void print5(int (*matrix)[4], int rowSize);
void error_msg(initializer_list<string> il);
void fx_ellipse(int i, ...);
void simple_printf(const char *fmt...);
int maxof(int n_args, ...);

int main() {
  /********************************************************
  6.2.1. Passing Arguments by Value
  (Exercise 6.10)
  ********************************************************/

  // initializing non-reference variable
  {
    int n = 0;  // ordinary variable of type int
    int i = n;  // i is a copy of the value in n
    i = 42;     // value in i is changed; n is unchanged
  }

  // Pointer Parameters
  {
    int n = 0, i = 42;
    int *p = &n, *q = &i;  // p points to n; q points to i
    *p = 42;               // value in n is changed; p is unchanged
    p = q;                 // p now points to i; values in i and n are unchanged

    i = 42;
    reset(&i);                    // changes i but not the address of i
    cout << "i = " << i << endl;  // prints i = 0
  }

  /********************************************************
  6.2.2. Passing Arguments by Reference
  (Exercises 6.11 ~ 6.15)
  ********************************************************/

  // operations on a reference
  {
    int n = 0, i = 42;
    int &r = n;  // r is bound to n (i.e., r is another name for n)
    r = 42;      // r and n is now 42
    r = i;       // n now has the same value as i
    i = r;       // i has the same value as n
  }

  // reset reference
  {
    int j = 42;
    resetRef(j);  // j is passed by reference; the value in j is changed
    cout << "j = " << j << endl;  // prints j = 0
  }

  // Using References to Avoid Copies
  {
    // arguments are not copied
    cout << isShorter("aaa", "bb") << endl;  // 0
  }

  // Using Reference Parameters to Return Additional Information
  {
    /*
    // returns the index of the first occurrence of c in s
    // the reference parameter occurs counts how often c occurs
    // https://stackoverflow.com/questions/4849632/vectorintsize-type-in-c
    string::size_type find_char(const string &s, char c,
                                string::size_type &occurs) {
      auto ret = s.size();  // position of the first occurrence, if any
      occurs = 0;           // set the occurrence count parameter
      for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
          if (ret == s.size()) ret = i;  // remember the first occurrence of c
          ++occurs;                      // increment the occurrence count
        }
      }
      return ret;  // count is returned implicitly in occurs
    }
    */

    size_t count = 0;
    size_t &ctr = count;
    auto index = find_char("Hello world", 'o', ctr);
    cout << "index: " << index << endl;  // 4
    cout << "count: " << count << endl;  // 2
    cout << "ctr: " << ctr << endl;      // 2
  }

  /********************************************************
  6.2.3. const Parameters and Arguments
  (Exercises 6.17 ~ 6.20)
  ********************************************************/

  // top-level const
  {
    // What are top-level const qualifiers?
    // https://stackoverflow.com/questions/7914444/what-are-top-level-const-qualifiers
    // A top-level const qualifier affects the object itself.
    // Others are only relevant with pointers and references.
    // They do not make the object const, and only prevent modification
    // through a path using the pointer or reference.

    const int ci = 42;    // we cannot change ci; const is top-level
    int i = ci;           // ok: when we copy ci, its top-level const is ignored
    i = 100;              // copied value doesn't have constness
    int *const ptr = &i;  // const is top-level; we can't assign to p
    *ptr = 0;             // ok: changes through p are allowed; i is now 0
  }

  // review - pointer & const
  {
    // What is the difference between
    //     const int*,
    //     const int * const, and
    //     int const *?
    // https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const

    /*
    // The ``Clockwise/Spiral Rule''
    // http://c-faq.com/decl/spiral.anderson.html

    -------------------------------------------------------------
    expressions         explanation                 constness
    -------------------------------------------------------------
    int*                pointer to int              none
    -------------------------------------------------------------
    int const *         pointer to const int        target value
                        == const int *
    -------------------------------------------------------------
    int * const         const pointer to int        pointer
    -------------------------------------------------------------
    int const * const   const pointer to const int  target value & pointer
                        == const int * const
    -------------------------------------------------------------

    int **              - pointer to pointer to int
    int ** const        - a const pointer to a pointer to an int
    int * const *       - a pointer to a const pointer to an int
    int const **        - a pointer to a pointer to a const int
    int * const * const - a const pointer to a const pointer to an int
    */

    // (1)
    int i = 100;                 // i is not const, i is not immutable
    int *const aptr = &i;        // aptr is const,
    *aptr = 200;                 // *aptr (== i) can be changed
    cout << "i: " << i << endl;  // 200

    // (2)
    int k = 200;
    const int j = 100;     // j is const, j is immutable
    int const *bptr = &j;  // bptr (NOT *bptr) can be changed
    bptr = &k;             // bptr is changed to non-const
    // *bptr = 300;        // *bptr can not be changed

    // (3)
    const int *cptr = &i;  // == int const *cptr
  }

  // pointer/reference & const
  {
    // We can initialize an object with a low-level const
    // from a nonconst object but not vice versa,
    // and a plain reference must be initialized
    // from an object of the same type.

    int i = 42;
    const int *cp = &i;  // ok: but cp can't change i
    const int &r1 = i;   // ok: but r can't change i
    const int &r2 = 42;  // ok:
    // int *p = cp;      // error: types of p and cp don't match
    // int &r3 = r1;     // error: types of r3 and r don't match
    // int &r4 = 42;     // error: can't ini a plain reference from a literal
  }

  // Pointer or Reference Parameters and const
  {
    int i = 0;
    const int ci1 = i;
    string::size_type ctr = 0;
    reset(&i);  // calls the version of reset that has an int* parameter
    // reset(&ci1); // error: can't init an int* from a ptr to a const int obj

    resetRef(i);  // calls the version of reset that has an int& parameter
    // reset(ci1);  // error: can't bind a plain reference to the const object
    // ci1 reset(42);  // error: can't bind a plain reference to a literal
    // reset(ctr);   // error: types don't match; ctr has an unsigned type
    // ok: find_char's first parameter is a reference to const
    find_char("Hello World!", 'o', ctr);
  }

  /********************************************************
  6.2.4. Array Parameters
  (Exercises 6.21 ~ 6.24)
  ********************************************************/

  // Array decay
  {
    /*
    void print(const int*);
    void print(const int[]);
    void print(const int[10]);

    Despite appearances, these three declarations of print are equivalent.
    Each function has a single parameter of type 'const int*'.
    When the compiler checks a call to print,
    it checks only that the argument has type 'const int*'.

    shows the intent that the function takes an array

    dimension for documentation purposes (at best)

    int i = 0, j[2] = {0, 1};
    print(&i); // ok: &i is int*
    print(j); // ok: j is converted to an int* that points to j[0]

    TODO: important, also in C lang
    Because arrays are passed as pointers (array decday),
    functions ordinarily don't know the size of the array they are given.
    They must rely on additional information provided by the caller.
    There are three common techniques used to manage pointer parameters.

    (1) Using a Marker to Specify the Extent of an Array
    (2) Using the Standard Library Conventions (WOW!!!)
    (3) Explicitly Passing a Size Parameter
    */

    // char *str = "This is a sample string.";  // ISO C++
    // TODO: std::string to char *
    // https://stackoverflow.com/questions/7352099/stdstring-to-char
    string str = "This is a sample string";
    const char *pstr = str.c_str();
    print1(pstr);

    int iarr[2] = {1, 2};
    print2(begin(iarr), end(iarr));
    print3(iarr, end(iarr) - begin(iarr));
  }

  // Array Parameters and const
  {
      // When a function does not need write access to the array elements,
      // the array parameter should be a pointer to const.
      // A parameter should be a plain pointer to a nonconst type
      // only if the function needs to change element values.
  }

  // Array Reference Parameters
  {
    int arr[10] = {1, 2, 3, 4, 5};
    print4(arr);

    int i = 0, j[2] = {0, 1};
    int k[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // print4(&i);  // error, arg is not an array of ten ints
    // print4(j);   // error, arg is not an array of ten ints
    print4(k);
  }

  // Passing a Multidimensional Array
  {
    int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    print5(arr, 3);

    // TODO: Array decay of multidimensional array?
  }

  /********************************************************
  6.2.5. main: Handling Command-Line Options
  (Exercises 6.25 ~ 6.26)
  ********************************************************/

  /*
  int main(int argc, char **argv) { ... }
  */

  /********************************************************
  6.2.6. Functions with Varying Parameters
  (Exercises 6.27 ~ 6.29)
  ********************************************************/

  // two ways for variadic function
  {
      // a. initilaizer_list
      // b. ellipsis parameters
  }

  // initilaizer_list
  {
    /*
    initializer_list<T> lst;
    initializer_list<T> lst{a,b,c,...};
    lst2(lst)
    lst2 - lst
    lst.size()
    lst.begin()
    lst.end()
    */

    initializer_list<int> il{1, 2, 3, 4, 5};

    // Unfortunately, initializer_list doesn't provide subscripting.
    // Why doesn't `std::initializer_list` provide a subscript operator?
    // https://stackoverflow.com/questions/17787394/why-doesnt-stdinitializer-list-provide-a-subscript-operator

    for (auto beg = il.begin(); beg != il.end(); ++beg) {
      cout << *beg << " ";
    }
    cout << endl;

    // When we pass a sequence of values to an initializer_list parameter,
    // we must enclose the sequence in curly braces.
    // TODO: braces ??

    string expected = "hello";
    string actual = "world";
    if (expected != actual)
      error_msg({"functionX", expected, actual});
    else
      error_msg({"functionX", "okay"});
  }

  // ellipsis parameters
  {
    // variadic function (varargs)
    // Variable number of arguments in C++?
    // https://stackoverflow.com/questions/1657883/variable-number-of-arguments-in-c

    fx_ellipse(10);
    simple_printf("dcff", 3, 'a', 1.999, 42.5);
    int m = maxof(3, 4, 2, 5, 8, 90, 1);
  }

  return 0;
}

/******************************************************************************
function definitions
******************************************************************************/

void reset(int *ip) {
  *ip = 0;  // changes the value of the object to which ip points
  ip = 0;   // changes only the local copy of ip; the argument is unchanged
}

void resetRef(int &i) {
  i = 0;
  // i is just another name for the object passed to reset
  // changes the value of the object to which i refers
}

void swapInt(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void swapIntRef(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

/* Using References to Avoid Copies */
// reference con't copy the value of variable
// compare the length of two strings
bool isShorter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}

/* Using Reference Parameters to Return Additional Information */
// returns the index of the first occurrence of c in s
// the reference parameter occurs counts how often c occurs
// https://stackoverflow.com/questions/4849632/vectorintsize-type-in-c
string::size_type find_char(const string &s, char c,
                            string::size_type &occurs) {
  auto ret = s.size();  // position of the first occurrence, if any
  occurs = 0;           // set the occurrence count parameter
  for (decltype(ret) i = 0; i != s.size(); ++i) {
    if (s[i] == c) {
      if (ret == s.size()) ret = i;  // remember the first occurrence of c
      ++occurs;                      // increment the occurrence count
    }
  }
  return ret;  // count is returned implicitly in occurs
}

bool is_sentence(const string &s) {
  // if there's a single period at the end of s, then s is a sentence
  string::size_type ctr = 0;
  return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}

void print1(const char *cp) {
  if (cp)
    // if cp is not a null pointer
    // TODO: if it is not char array?  --> disaster
    while (*cp)
      // so long as the character it points to is not a null character
      cout << *cp++;  // print the character and advance the pointer
}

// TODO: very useful functions
// https://en.cppreference.com/w/cpp/iterator/begin
// https://en.cppreference.com/w/cpp/iterator/end
void print2(const int *beg, const int *end) {
  // print every element starting at beg up to but not including end
  while (beg != end) cout << *beg++ << endl;
  // print the current element
  // and advance the pointer
}

// const int ia[] is equivalent to const int* ia
// size is passed explicitly and used to control access to elements of ia
void print3(const int ia[], size_t size) {
  for (size_t i = 0; i != size; ++i) {
    cout << ia[i] << " ";
  }
  cout << endl;
}

// ok: parameter is a reference to an array; the dimension is part of the type
// TODO: reference to array, array to reference(is this possible?)
void print4(int (&arr)[10]) {
  for (auto elem : arr) cout << elem << " ";
  cout << endl;
}

// matrix points to the first element in an array
// whose elements are arrays of ten ints
void print5(int (*matrix)[4], int rowSize) {
  for (int i = 0; i < rowSize; i++) {
    for (int j = 0; j < 4; j++) {
      cout << (*(matrix + i))[j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

// Functions with Varying Parameters
// initializer_list<T>
// https://en.cppreference.com/w/cpp/utility/initializer_list
void error_msg(initializer_list<string> il) {
  for (auto beg = il.begin(); beg != il.end(); ++beg) cout << *beg << " ";
  cout << endl;
}

void fx_ellipse(int i, ...) {
  va_list start;  // va_list found in <cstdarg> and start is its type
  int list;

  /*** initializes 'start' with the information to access the value present
   * after 'i' ***/
  va_start(start, i);

  /*** va_arg( ) will return the value present in the argument list
   * consecutively ***/
  while ((list = va_arg(start, int)) != 0) {
    cout << list << " ";
  }
  cout << endl;

  va_end(start);  // ends the use of va_list
}

// TODO: C-style "const char* fmt, ..." is also valid
// https://en.cppreference.com/w/cpp/utility/variadic
void simple_printf(const char *fmt...) {
  va_list args;
  va_start(args, fmt);

  while (*fmt != '\0') {
    if (*fmt == 'd') {
      int i = va_arg(args, int);
      std::cout << i << '\n';
    } else if (*fmt == 'c') {
      // note automatic conversion to integral type
      int c = va_arg(args, int);
      std::cout << static_cast<char>(c) << '\n';
    } else if (*fmt == 'f') {
      double d = va_arg(args, double);
      std::cout << d << '\n';
    }
    ++fmt;
  }

  va_end(args);
}

// Variable number of arguments in C++?
// https://stackoverflow.com/questions/1657883/variable-number-of-arguments-in-c
int maxof(int n_args, ...) {
  va_list ap;
  va_start(ap, n_args);
  int max = va_arg(ap, int);
  for (int i = 2; i <= n_args; i++) {
    int a = va_arg(ap, int);
    if (a > max) max = a;
  }
  va_end(ap);
  return max;
}

/*
Section 6.3 Return Types and the return Statement
Section 6.4 Overloaded Functions
Section 6.5 Features for Specialized Uses
Section 6.6 Function Matching
Section 6.7 Pointers to Functions
*/