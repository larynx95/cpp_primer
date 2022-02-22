/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 6. Functions

Section 6.1 Function Basics
Section 6.2 Argument Passing
Section 6.3 Return Types and the return Statement
Section 6.4 Overloaded Functions

// functions taking const and nonconst references
// or pointers have different parameters
// declarations for four independent, overloaded functions
Record lookup(Account&); // function that takes a reference to Account
Record lookup(const Account&); // new function that takes a const reference
Record lookup(Account*); // new function, takes a pointer to Account
Record lookup(const Account*); // new function, takes a pointer to const
******************************************************************************/

#include <iostream>
#include <vector>

#include "Sales_data.h"
using namespace std;

void print(const char *cp);
void print(const int *beg, const int *end);
void print(const int ia[], size_t size);

const string &shorterString(const string &s1, const string &s2);
string &shorterString(string &s1, string &s2);

int main() {
  // Same name, different parameters
  {
    /*
    void print(const char *cp);
    void print(const int *beg, const int *end);
    void print(const int ia[], size_t size);
    */

    int j[2] = {0, 1};
    print("Hello World");         // calls print(const char*)
    print(j, end(j) - begin(j));  // calls print(const int*, size_t)
    print(begin(j), end(j));      // calls print(const int*, const int*)
  }

  // Defining Overloaded Functions
  {
      /*
      Record lookup(const Account &); // find by Account
      Record lookup(const Phone&);    // find by Phone
      Record lookup(const Name&);     // find by Name

      Account acct;
      Phone phone;
      Record r1 = lookup(acct); // call version that takes an Account
      Record r2 = lookup(phone); // call version that takes a Phone
      */
  }

  // Determining Whether Two Parameter Types Differ
  {
      /*
      // each pair declares the same function
      Record lookup(const Account &acct);
      Record lookup(const Account&); // parameter names are ignored

      typedef Phone Telno;
      Record lookup(const Phone&);
      Record lookup(const Telno&); // Telno and Phone are the same type
      */
  }

  // Overloading and const Parameters
  {
      /*
      Record lookup(Phone);
      Record lookup(const Phone);   // redeclares Record lookup(Phone)

      Record lookup(Phone*);
      Record lookup(Phone* const);  // redeclares Record lookup(Phone*)
      */
  }

  // const_cast and Overloading
  {
    string s1 = "hello";
    string s2 = "world";
    auto res = shorterString(s1, s2);
    cout << res << endl;
  }

  // Calling an Overloaded Function
  {
    // function matching (overload resolution)
  }

  /********************************************************
  6.4.1. Overloading and Scope
  ********************************************************/

  /*
  string read();
  void print(const string &);
  void print(double);
  void fooBar(int ival){
    bool read = false;  // new scope: hides the outer declaration of read
    string s = read();  // error: read is a bool variable, not a function
    // bad practive: usually it's a bad idea to declare functions at local scope
    void print(int);    // new scope: hides previous instances of print
    print("Value: ")    // error: print(const string &) is hidden
    print(ival);        // ok: print(int) is visible
    print(3.14);        // ok: calls print(int); print(double) is hidden
  }
  */

  return 0;
}

void print(const char *cp) {
  if (cp)
    while (*cp) cout << *cp++;
  cout << endl;
}

void print(const int *beg, const int *end) {
  while (beg != end) cout << *beg++ << " ";
  cout << endl;
}

void print(const int ia[], size_t size) {
  for (size_t i = 0; i != size; ++i) cout << ia[i] << " ";
  cout << endl;
}

// return a reference to the shorter of two strings
const string &shorterString(const string &s1, const string &s2) {
  return s1.size() <= s2.size() ? s1 : s2;
}

// TODO: Check this again, const_cast
string &shorterString(string &s1, string &s2) {
  auto &r = shorterString(const_cast<const string &>(s1),
                          const_cast<const string &>(s2));
  return const_cast<string &>(r);
}

/*
Section 6.5 Features for Specialized Uses
Section 6.6 Function Matching
Section 6.7 Pointers to Functions
*/