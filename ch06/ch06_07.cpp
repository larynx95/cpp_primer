/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 6. Functions

Section 6.1 Function Basics
Section 6.2 Argument Passing
Section 6.3 Return Types and the return Statement
Section 6.4 Overloaded Functions
Section 6.5 Features for Specialized Uses
Section 6.6 Function Matching
Section 6.7 Pointers to Functions (Exercises 6.54 ~ 56)

TODO: check this again
******************************************************************************/

#include <iostream>
using namespace std;

bool lengthCompare(const string &, const string &);
void ff(int *val);
void ff(unsigned int val);
bool longerStr(const string &s1, const string &s2);
void useBigger(const string &s1, const string &s2,
               bool pf(const string &, const string &));

void useBigger2(const string &s1, const string &s2,
                bool (*pf)(const string &, const string &));

int *fx1(int *a, int b);

string::size_type sumLength(const string &, const string &);
string::size_type largerLength(const string &, const string &);

// returning a pointer to function
using F = int(int *, int);
using PF = int (*)(int *, int);

decltype(sumLength) *getFcn(const string &s);

typedef decltype(sumLength) func_type;
func_type *getFcn2(const string &s);

int main() {
  // function pointer
  {
    // function points to a function returning bool
    // that takes two const string references
    bool (*pf)(const string &, const string &);  // uninitialized
  }

  // Using Function Pointers
  {
    bool (*pf)(const string &, const string &);
    pf = lengthCompare;   // pf now points to the function, lengthCompare
    pf = &lengthCompare;  // == assignment: address-of operator is optional

    cout << lengthCompare("aaa", "aa") << endl;  // 1
    cout << pf("aaa", "aa") << endl;             // 1
    cout << (*pf)("aaa", "aa") << endl;          // 1

    bool b1 = pf("hello", "goodbye");     // calls lengthCompare
    bool b2 = (*pf)("hello", "goodbye");  // equivalent call, explicit
    // TODO: pf == (*pf) ??
    // we can use a pointer to a function to call the function
    // to which the pointer points.
    // We can do so directly—there is no need to dereference the pointer
    bool b3 = lengthCompare("hello", "goodbye");  // equivalent call
  }

  // Pointers to Overloaded Functions
  {
    // The type of the pointer must match.
    // void (*pf2)(int) = ff         // error
    // double (*pf3)(int *) = ff;   // error
    void (*pf4)(unsigned int) = ff;
  }

  // Function Pointer Parameters (Higer-Order Function)
  {
    useBigger("aaa", "aa", longerStr);
    useBigger2("aaa", "aa", longerStr);
  }

  // Returning a Pointer to Function
  {
    // using F = int (int*, int);
    // using PF = int(*)(int*, int);
    // PF f1(int);   // ok, PF is a pointer to fx; f1 returns a pointer to fx
    // F f1(int);    // error: F is a fx type; f1 can't return a fx
    // F *f1(int);   // ok: specify that the return type is apointer to fx

    auto f1(int)->int (*)(int *, int);
    cout << typeid(f1).name() << endl;
  }

  // Using auto or decltype for Function Pointer Types
  {
    // TODO: Using auto or decltype for Function Pointer Types in C++ primer
    // https://stackoverflow.com/questions/36503577/using-auto-or-decltype-for-function-pointer-types-in-c-primer

    string str1, str2;
    str1 = "Hello";
    str2 = "world";

    // calls either sumLength or largerLength with str1, str2
    // depending on str1's size
    auto i = getFcn(str1)(str1, str2);
    //       ------------  this is pointer to function
    cout << "i: " << i << endl;

    i = (*getFcn(str1))(str1, str2);
    cout << "i: " << i << endl;

    auto j = getFcn2(str1)(str1, str2);
    cout << "j: " << i << endl;

    j = (*getFcn2(str1))(str1, str2);
    cout << "j: " << i << endl;
  }

  /* pointers to functions */

  return 0;
}

/******************************************************************************
function definitions
******************************************************************************/

bool lengthCompare(const string &s1, const string &s2) {
  return s1.size() > s2.size();
}

void ff(int *val) {
  *val++;
  cout << "*val: " << *val << endl;
}

void ff(unsigned int val) { cout << "val: " << val << endl; }

bool longerStr(const string &s1, const string &s2) { return s1 > s2; }

void useBigger(const string &s1, const string &s2,
               bool pf(const string &, const string &)) {
  if (pf(s1, s2)) {
    cout << "The first string is longer than the second one." << endl;
  }
}

void useBigger2(const string &s1, const string &s2,
                bool (*pf)(const string &, const string &)) {
  if (pf(s1, s2)) {
    cout << "The first string is longer than the second one." << endl;
  }
}

int *fx1(int *a, int b) {
  *a += b;
  return a;
}

string::size_type sumLength(const string &s1, const string &s2) {
  return s1.size() + s2.size();
}

string::size_type largerLength(const string &s1, const string &s2) {
  auto size1 = s1.size();
  auto size2 = s2.size();
  if (size1 > size2) return size1;
  return size2;
}

// TODO: Using auto or decltype for Function Pointer Types in C++ primer
// https://stackoverflow.com/questions/36503577/using-auto-or-decltype-for-function-pointer-types-in-c-primer

// depending on the value of its string parameter,
// getFcn returns a pointer to sumLength or to largerLength
decltype(sumLength) *getFcn(const string &s) {
  if (s.size() < 10)  // magic number
    return sumLength;
  else
    return largerLength;
}

func_type *getFcn2(const string &s) {
  if (s.size() < 10)  // magic number
    return sumLength;
  else
    return largerLength;
}