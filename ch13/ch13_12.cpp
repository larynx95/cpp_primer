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
13.2 Copy Control and Resource Management
  13.2.1 Classes That Act Like Values

************************************************/

#include <iostream>
#include <vector>

using namespace std;

class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  // each HasPtr has its own copy of the string to which ps points
  HasPtr(const HasPtr &p) : ps(new std::string(*p.ps)), i(p.i) {}
  HasPtr &operator=(const HasPtr &);
  ~HasPtr() { delete ps; }

 private:
  std::string *ps;
  int i;
};

int main() {
  //
  return 0;
}