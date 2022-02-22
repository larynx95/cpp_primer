/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Section 10.1 Overview
******************************************************************************/

/*
- How the Algorithms Work
- Iterators Make the Algorithms Container Independent, ...
- ...But Algorithms Do Depend on Element-Type Operations

*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>
using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::find;
using std::list;
using std::string;
using std::vector;

int main() {
  int ia[] = {27, 210, 12, 47, 109, 83};
  int val = 83;
  int* result = find(begin(ia), end(ia), val);
  cout << "The value " << val
       << (result == end(ia) ? " is not present" : " is present") << endl;

  // search starting from ia[1] up to but not including ia[4]
  result = find(ia + 1, ia + 4, val);

  // initialize the vector with some values
  vector<int> vec = {27, 210, 12, 47, 109, 83};
  val = 42;  // value we'll look for

  // result2 will denote the element we want if it's in vec,
  // or vec.cend() if not
  auto result2 = find(vec.cbegin(), vec.cend(), val);

  // report the result
  cout << "The value " << val
       << (result2 == vec.cend() ? " is not present" : " is present") << endl;

  // now use find to look in a list of strings
  list<string> lst = {"val1", "val2", "val3"};

  string sval = "a value";  // value we'll look for
  // this call to find looks through string elements in a list
  auto result3 = find(lst.cbegin(), lst.cend(), sval);
  cout << "The value " << sval
       << (result3 == lst.cend() ? " is not present" : " is present") << endl;

  return 0;
}

/*
Section 10.2 A First Look at the Algorithms
Section 10.3 Customizing Operations
Section 10.4 Revisiting Iterators
Section 10.5 Structure of Generic Algorithms
Section 10.6 Container-Specific Algorithms
*/