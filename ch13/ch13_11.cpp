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
  13.1.5 Using = default
  13.1.6 Preventing Copies
    Defining a Function as Deleted
    The Destructor Should Not be a Deleted Member
    The Copy-Control Members May Be Synthesized as Deleted
    private Copy Control

************************************************/

#include <iostream>
#include <vector>

using namespace std;

struct NoCopy {
  NoCopy() = default;               // use the synthesized default constructor
  NoCopy(const NoCopy &) = delete;  // no copy
  NoCopy &operator=(const NoCopy &) = delete;  // no assignment
  ~NoCopy() = default;                         // use the synthesized destructor
  // other members
};

class PrivateCopy {
  // no access specifier; following members are private by default; see § 7.2
  // (p. 268) copy control is private and so is inaccessible to ordinary user
  // code
  PrivateCopy(const PrivateCopy &);
  PrivateCopy &operator=(const PrivateCopy &);
  // other members
 public:
  PrivateCopy() = default;  // use the synthesized default constructor
  ~PrivateCopy();  // users can define objects of this type but not copy them
};

int main() {
  //
  return 0;
}