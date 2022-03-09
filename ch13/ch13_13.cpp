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
    Valuelike Copy-Assignment Operator

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

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
  auto newp = new string(*rhs.ps);  // copy the underlying string
  delete ps;                        // free the old memory
  ps = newp;                        // copy data from rhs into this object
  i = rhs.i;
  return *this;  // return this object
}

/*
// WRONG way to write an assignment operator!
HasPtr &HasPtr::operator=(const HasPtr &rhs) {
  delete ps;  // frees the string to which this object points
  // if rhs and *this are the same object, we’re copying from deleted memory!
  ps = new string(*(rhs.ps));
  i = rhs.i;
  return *this;
}
*/

int main() {
  //
  return 0;
}