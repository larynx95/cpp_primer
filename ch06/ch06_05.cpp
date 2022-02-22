/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 6. Functions

Section 6.1 Function Basics
Section 6.2 Argument Passing
Section 6.3 Return Types and the return Statement
Section 6.4 Overloaded Functions
Section 6.5 Features for Specialized Uses
******************************************************************************/

#include <cassert>  // assert
#include <iostream>
#include <string>
using namespace std;

typedef string::size_type sz;
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');

int default_fx(int a = 1, int b = 2);
inline const string &shorterString(const string &s1, const string &s2);
constexpr int new_sz() { return 42; }  // TODO: prototype?
constexpr size_t scale(size_t cnt);

int main() {
  /********************************************************
  6.5.1. Default Arguments (Exercises 6.40 ~ 6.42)
  ********************************************************/

  // Default arguments
  // https://en.cppreference.com/w/cpp/language/default_arguments

  // string::size_type
  {
    string hello = "hello";
    cout << hello.size() << endl;
    cout << typeid(hello.size()).name() << endl;  // m (size_type in g++)
  }

  // Calling Functions with Default Arguments
  {
    cout << default_fx() << endl;        // 3
    cout << default_fx(10) << endl;      // 12
    cout << default_fx(10, 20) << endl;  // 30
  }

  // Default Argument Declarations
  {
      // Default value of function parameter
      // https://stackoverflow.com/questions/2842928/default-value-of-function-parameter

      // Where to put default parameter value in C++? [duplicate]
      // https://stackoverflow.com/questions/4989483/where-to-put-default-parameter-value-in-c
  }

  // Default Argument Initializers
  {
      // a default argument can be any expression that has a type
      // that is convertible to the type of the parameter
  }

  /********************************************************
  6.5.2. Inline and constexpr Functions (Exercises 6.43 ~ 46)
  ********************************************************/

  // inline Functions Avoid Function Call Overhead
  {
    string s1 = "aaa";
    string s2 = "aa";
    cout << shorterString(s1, s2) << endl;              // inline, same as below
    cout << (s1.size() < s2.size() ? s1 : s2) << endl;  // same as above
  }

  // constexpr Functions
  {
    auto result = new_sz();
    cout << typeid(result).name() << endl;  // i
    cout << result << endl;                 // 42

    int arr[scale(2)];  // ok: scale(2) is a constant expression
    int i = 2;          // i is not a constant expression
    // int a2[scale(i)];   // error: scale(i) is not a constant expression

    /* constexpr functions
    TODO: Is it possible to declare constexpr class in a header and define it in
    a separate .cpp file?
    https://stackoverflow.com/questions/27345284/is-it-possible-to-declare-constexpr-class-in-a-header-and-define-it-in-a-separat
    */
  }

  // Put inline and constexpr Functions in Header Files

  /********************************************************
  6.5.3. Aids for Debugging
  ********************************************************/

  // The assert Preprocessor Macro
  {
    int threshold = 3;
    string word = "hello";
    assert(word.size() > threshold);
  }

  // The NDEBUG Preprocessor Variable (TODO: What is this?)
  {
    // If NDEBUG is defined, assert does nothing.
    // By default, NDEBUG is not defined,
    // so, by default, assert performs a run-time check.
  }

  return 0;
}

/******************************************************************************
function definitions
******************************************************************************/

int default_fx(int a, int b) {
  // You should put the default arguments in the prototype,
  // not the definition
  return a + b;
}

inline const string &shorterString(const string &s1, const string &s2) {
  return s1.size() <= s2.size() ? s1 : s2;
}

// scale(arg) is a constant expression if arg is a constant expression
constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }

/*
Section 6.6 Function Matching
Section 6.7 Pointers to Functions
*/