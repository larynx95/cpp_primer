/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 05. Statements

5.1. Simple Statements
5.2. Statement Scope
******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  // find the first negative element
  vector<int> v = {1, 2, 3};
  auto beg = v.begin();
  while (beg != v.end() && *beg >= 0) {
    cout << *beg << endl;
    ++beg;
  }
  if (beg == v.end()) cout << "end: " << *beg << endl;

  return 0;
}

/*
5.3. Conditional Statements
5.4. Iterative Statements
5.5. Jump Statements
5.6. try Blocks and Exception handling
*/