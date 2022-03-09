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
************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Foo {
 public:
  Foo& operator=(const Foo&);  // assignment operator
  // ...
};

int main() {
  //
  return 0;
}