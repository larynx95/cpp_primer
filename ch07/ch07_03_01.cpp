/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 7. Classes

Section 7.1 Defining Abstract Data Types
Section 7.2 Access Control and Encapsulation
Section 7.3 Additional Class Features
******************************************************************************/

/*
7.3.1. Class Members Revisited (Exercises 7.23~7.26)
- Defining a Type Member
- Member Functions of class Screen
- Making Members inline
- Overloading Member Functions
- mutable Data Members
- Initializers for Data Members of Class Type
*/

// https://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm

#include <iostream>
#include <vector>

using namespace std;

class Screen {
 public:
  typedef std::string::size_type pos;
  // using pos = std::string::size_type;  // same as above, type alias
  Screen() = default;  // needed because Screen has another constructor
  // cursor initialized to 0 by its in-class initializer
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  char get() const {
    // get the character at the cursor
    return contents[cursor];
  }                                       // implicitly inline
  inline char get(pos ht, pos wd) const;  // explicitly inline
  Screen &move(pos r, pos c);             // can be made inline later
  void some_member() const;

 private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  mutable size_t access_ctr;  // may change even in a const object
  // other members as before
  /*
  It sometimes (but not very often) happens that a class has a data member
  that we want to be able to modify, even inside a const member function.
  We indicate such members by including the mutable keyword in their
  declaration.

  A mutable data member is never const,
  even when it is a member of a const object.
  Accordingly, a const member function may change a mutable member.
  */
};

class Window_mgr {
 private:
  // Screens this Window_mgr is tracking
  // by default, a Window_mgr has one standard sized blank Screen
  std::vector<Screen> screens{Screen(24, 80, ' ')};
};

int main() {
  Screen myscreen;
  char ch = myscreen.get();  // calls Screen::get()
  ch = myscreen.get(0, 0);   // calls Screen::get(pos, pos);

  return 0;
}

// we can specify inline on the definition
inline Screen &Screen::move(pos r, pos c) {
  pos row = r * width;  // compute the row location
  cursor = row + c;     // move cursor to the column within that row
  return *this;         // return this object as an lvalue
}

// declared as inline in the class
char Screen::get(pos r, pos c) const {
  pos row = r * width;       // compute row location
  return contents[row + c];  // return character at the given column
}

void Screen::some_member() const {
  ++access_ctr;  // keep a count of the calls to any member function
  // whatever other work this member needs to do
}

/*
Section 7.4 Class Scope
Section 7.5 Constructors Revisited
Section 7.6 static Class Members
*/