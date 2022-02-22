/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 05. Statements

5.1. Simple Statements
******************************************************************************/

#include <iostream>
using namespace std;

int main() {
  // Null Statements
  {
    ;  // null statement
  }

  // Beware of Missing or Extraneous Semicolons

  // Compound Statements (Blocks)
  {
    int val = 0, sum = 0;
    while (val <= 3) {
      sum += val;
      ++val;
    }
    cout << "sum, val: " << sum << ", " << val << endl;
  }

  return 0;
}

/*
5.2. Statement Scope
5.3. Conditional Statements
5.4. Iterative Statements
5.5. Jump Statements
5.6. try Blocks and Exception handling
*/