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
************************************************/

#include <iostream>
#include <vector>

#include "Sales_data.h"

using namespace std;

// equivalent to the synthesized copy-assignment operator
Sales_data& Sales_data::operator=(const Sales_data& rhs) {
  bookNo = rhs.bookNo;          // calls the string::operator=
  units_sold = rhs.units_sold;  // uses the built-in int assignment
  revenue = rhs.revenue;        // uses the built-in double assignment
  return *this;                 // return a reference to this object
}

int main() {
  //
  return 0;
}