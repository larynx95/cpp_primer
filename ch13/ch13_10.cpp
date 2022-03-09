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
    The Synthesized Destructor
  13.1.4 The Rule of Three/Five
    Classes That Need Destructors Need Copy and Assignment
    Classes That Need Copy Need Assignment, and Vice Versa
************************************************/

/*
rule of three:
  - copy ctor
  - copy assignment operator
  - destructor
rule of five:
  + move ctor
  + move assignment operator
*/

#include <iostream>
#include <vector>

#include "Sales_data.h"

using namespace std;

class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  ~HasPtr() { delete ps; }
  // WRONG: HasPtr needs a copy constructor and copy-assignment operator
  // other members as before
};

int main() {
  //
  return 0;
}