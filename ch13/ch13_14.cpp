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
  13.2.2 Defining Classes That Act Like Pointers
    Reference Counts
    Defining a Reference-Counted Class

************************************************/

#include <iostream>
#include <vector>

using namespace std;

class HasPtr {
 public:
  // constructor allocates a new string and a new counter, which it sets to 1
  HasPtr(const std::string &s = std::string())
      : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
  // copy constructor copies all three data members and increments the counter
  HasPtr(const HasPtr &p) : ps(p.ps), i(p.i), use(p.use) { ++*use; }
  HasPtr &operator=(const HasPtr &);
  ~HasPtr();

 private:
  std::string *ps;
  int i;
  std::size_t *use;  // member to keep track of how many objects share *ps
};

int main() {
  //
  return 0;
}