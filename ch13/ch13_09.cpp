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
************************************************/

#include <iostream>
#include <vector>

#include "Sales_data.h"

using namespace std;

class Sales_data {
 public:
  // no work to do other than destroying the members, which happens
  // automatically
  ~Sales_data() {}
  // other members as before
};

int main() {
  //
  return 0;
}