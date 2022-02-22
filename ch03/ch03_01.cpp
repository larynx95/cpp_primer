/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 3. Strings, Vectors, and Arrays

Section 3.1 Namespace using Declarations
******************************************************************************/

#include <climits>
#include <iostream>

// using declarations for names from the standard library
// using namespace::name;
// (::) - scope operator
using std::cin;
using std::cout;
using std::endl;

// idiomatic use of std::cin
int InputInt() {
  int iInput;
  cin >> iInput;

  if (cin.fail()) {
    cin.clear();
    cin.ignore(1024, '\n');
    return INT_MAX;
  }
  return iInput;
}

int main() {
  // using namespace of "std"
  cout << "Enter two numbers: ";
  int v1, v2;
  cin >> v1 >> v2;
  cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << endl;

  // idiomatic expression - std::cin
  int iVal = InputInt();
  cout << "iVal: " << iVal << endl;

  return 0;
}

/*
Section 3.2 Library string Type
Section 3.3 Library vector Type
Section 3.4 Introducing Iterators
Section 3.5 Arrays
Section 3.6 Multidimensional Arrays
*/