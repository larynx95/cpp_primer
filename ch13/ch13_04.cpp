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
************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  // compiler bypass copy constructor
  string null_book = "9-999-99999-9";  // copy initialization
  string null_book2("9-999-99999-9");  // compiler omits the copy constructor

  return 0;
}