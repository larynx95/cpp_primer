/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 6. Functions

Section 6.1 Function Basics
******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int fact(int val) {
  int ret = 1;  // local variable to hold the result as we calculate it
  while (val > 1) ret *= val--;  // assign ret * val to ret and decrement val
  return ret;                    // return the result
}

size_t count_calls() {
  static size_t ctr = 0;
  return ++ctr;
}

void print(vector<int>::const_iterator beg, vector<int>::const_iterator end);

int main() {
  /********************************************************
  6.1.1. Local Objects
  (Exercises 6.6 ~ 6.7)
  ********************************************************/

  // scope, lifetime
  {
      // - The scope of a name is
      //   the part of the program's text in which that name is visible.
      // - The lifetime of an object is
      //   the time during the program’s execution that the object exists.
  }

  // Automatic Objects

  // Local static Objects
  {
    for (size_t i = 0; i != 10; ++i) {
      cout << count_calls() << " ";  // 1 2 3 4 5 6 7 8 9 10
    }
    cout << endl;
  }

  /********************************************************
  6.1.2. Function Declarations
  (Exercises 6.8)
  ********************************************************/

  // Function Declarations Go in Header Files

  /********************************************************
  6.1.3. Separate Compilation
  (Exercises 6.9)
  ********************************************************/

  // Compiling and Linking Multiple Source Files

  return 0;
}

/*
Section 6.2 Argument Passing
Section 6.3 Return Types and the return Statement
Section 6.4 Overloaded Functions
Section 6.5 Features for Specialized Uses
Section 6.6 Function Matching
Section 6.7 Pointers to Functions
*/