/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 13. Copy Control

13.1 Copy, Assign, and Destroy
  13.1.1 The Copy Constructor
    The Synthesized Copy Constructor
    Copy Initialization
    Parameters and Return Values
    Constraints on Copy Initialization
    The Compiler Can Bypass the Copy Constructor
  13.1.2 The Copy-Assignment Operator
    Introducing Overloaded Assignment
    The Synthesized Copy-Assignment Operator
  13.1.3 The Destructor
    What a Destructor Does
    When a Destructor Is Called
************************************************/

#include <iostream>
#include <vector>

#include "Sales_data.h"

using namespace std;

class Foo {
 public:
  ~Foo();  // destructor
  // ...
};

int main() {
  {  // new scope
    // p and p2 point to dynamically allocated objects
    Sales_data *p = new Sales_data;       // p is a built-in pointer
    auto p2 = make_shared<Sales_data>();  // p2 is a shared_ptr
    Sales_data item(*p);     // copy constructor copies *p into item
    vector<Sales_data> vec;  // local object
    vec.push_back(*p2);      // copies the object to which p2 points
    delete p;                // destructor called on the object pointed to by p
  }  // exit local scope; destructor called on item, p2, and vec
  // destroying p2 decrements its use count; if the count goes to 0, the object
  // is freed destroying vec destroys the elements in vec

  return 0;
}