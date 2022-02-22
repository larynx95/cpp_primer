/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Section 2.1 Primitive Built-in Types

******************************************************************************/

#include <iostream>

int main() {
  /********************************************************
  2.1.1. Arithmetic Types
  (Exercises 2.1 ~ 2.2)

  Primitive types
    arithmetic types
      characters
      integers
      boolean values
      floating-point numbers
    void type

  bit  : smallest unit of storage, 0 or 1
  byte : 8 bits, store one character
  word : 32 bits

  Type         Meaning
  -------------------------------------------------
  bool         boolean                             NA
  char         character                           8 bits
  wchar_t      wide char                          16 bits
  char16_t     unicode character                  16 bits
  char32_t     unicode character                  32 bits
  short        short integer                      16 bits
  int          integer                            16 bits
  long         long integer                       32 bits
  long long    long integer                       64 bits
  float        single-precision floating-point    6  significant digits
  double       double-precision floating-point    10 significant digits
  long double  extended-precision floating point  10 significant digits

  2.1.2. Type Conversions
  (Exercises 2.3 ~ 2.4)
  ********************************************************/

  bool b = 42;  // b is true
  std::cout << "b is " << b << std::endl;

  int i = b;  // i has value 1
  std::cout << "i is " << i << std::endl;

  i = 3.14;  // i has value 3
  std::cout << "i is " << i << std::endl;

  double pi = i;  // pi has value 3.0
  std::cout << "pi is " << pi << std::endl;

  unsigned char c = -1;  // assuming 8-bit chars, c has value 255
  std::cout << "c is " << c << std::endl;
  // signed char c2 = 256;
  // assuming 8-bit chars, the value of c2 is undefined
  // std::cout << "c2 is " << c2 << std::endl;

  /* truthy and falsy of integer value */
  if (i) std::cout << i << std::endl;
  // condition will evaluate as true
  // If the value is 0, then the condition is false;
  // all other (nonzero) values yield true.

  /* unsigned integer value */
  unsigned u = 10;
  i = -42;
  std::cout << i + i << std::endl;  // prints -84
  std::cout << u + i << std::endl;  // if 32-bit ints, prints 4294967264

  unsigned u1 = 42, u2 = 10;
  std::cout << u1 - u2 << std::endl;  // ok: result is 32
  std::cout << u2 - u1 << std::endl;  // ok: but the result will wrap around

  /* looping for unsigned value */
  for (int i = 10; i >= 0; --i) std::cout << i << std::endl;
  // for (unsigned u = 10; u >= 0; --u) std::cout << u << std::endl;
  // WRONG: u can never be less than 0; the condition will always succeed

  u = 11;
  // start the loop one past the first element we want to print
  while (u > 0) {
    u--;  // decrement first, so that the last iteration will print 0
    std::cout << u << std::endl;
  }

  /********************************************************
  2.1.3 Literals
  (Exercises 2.5 ~ 2.6)

    integer and floating-point literals
    (1) character and character string literals
      prefix  meaning           type
      u       unicode 16 chars  char16_t
      U       unicode 32 chars  char32_t
      L       wide chars        wchar_T
      u8      utf-8             char (str literal only)
    (2) integer literals
      suffix    minimum type
      u or U    unsigned
      l or L    long
      ll or LL  long long
    (3) floating-point literals
      suffix    type
      f or F    float
      l or L    long double

  escape sequences
  newline \n          horizontal tab \t   alert (bell) \a
  vertical tab \v     backspace \b        double quote \"
  backslash \\        question mark \?    single quote \'
  carriage return \r  formfeed \f

  \7 (bell) \12 (newline) \40 (blank)
  \0 (null) \115 ('M') \x4d ('M')

  L'a' // wide character literal, type is wchar_t
  u8"hi!" // utf-8 string literal (utf-8 encodes a Unicode character in 8 bits)
  42ULL // unsigned integer literal, type is unsigned long long
  1E-3F // single-precision floating-point literal, type is float
  3.14159L // extended-precision floating-point literal, type is long double
  ********************************************************/

  std::cout << "a really, really long string literal "
               "that spans two lines"
            << std::endl;

  std::cout << '\n';       // prints a newline
  std::cout << "\tHi!\n";  // prints a tab followd by "Hi!" and a newline
  std::cout << "\a";       // bell

  std::cout << "Hi \x4dO\115!\n";
  // prints Hi MOM! followed by a newline (hexdecimal)
  std::cout << '\115' << '\n';  // prints M followed by a newline (octal)

  return 0;
}

/*
Section 2.2 Variables
Section 2.3 Compound Types
Section 2.4 const Qualifier
Section 2.5 Dealing with Types
Section 2.6 Defining Our Own Data Structures
*/
