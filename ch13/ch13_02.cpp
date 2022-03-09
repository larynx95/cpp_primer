/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 13. Copy Control

13.1 Copy, Assign, and Destroy
  13.1.1 The Copy Constructor
    The Synthesized Copy Constructor
    Copy Initialization
************************************************/

/*
copy initialization happens when...
- we define variables using and '='
- Pass an object as an argument to a parameter of nonreference type
- Return an object from a function that has a nonreference return type
- Brace initialize the elements in an array or the members of an aggregate class

Copy constructors
https://en.cppreference.com/w/cpp/language/copy_constructor
  class-name ( const class-name & )              (1)
  class-name ( const class-name & ) = default;   (2)  (since C++11)
  class-name ( const class-name & ) = delete;    (3)  (since C++11)

Copy initialization
https://en.cppreference.com/w/cpp/language/copy_initialization
  T object = other;               (1)
  T object = {other};             (2)  (until C++11)
  f(other)                        (3)
  return other;                   (4)
  throw object;
  catch (T object)                (5)
  T array[N] = {other-sequence};  (6)
*/

#include <iostream>

int main() {
  std::string dots(10, '.');                  // direct initilaization
  std::string s(dots);                        // direct initialization
  std::string s2 = dots;                      // copy initialization
  std::string null_book = "9-999-99999-9";    // copy initialization
  std::string nines = std::string(100, '9');  // copy initialization

  return 0;
}