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
7.3.2. Functions That Return *this (Exercises 7.27~7.30)
  - Functions That Return *this
  - Returning *this from a const Member Function
  - Overloading Based on const
*/

// https://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm

#include <iostream>
#include <vector>

using namespace std;

/**********************************************************
class
**********************************************************/

class Screen {
 public:
  typedef std::string::size_type pos;
  Screen() = default;
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  char get() const { return contents[cursor]; }
  inline char get(pos ht, pos wd) const;
  Screen &move(pos r, pos c);
  void some_member() const;

  // function returning `*this`
  Screen &set(char);
  Screen &set(pos, pos, char);

  // display overloaded on whether the object is const or not
  Screen &display(std::ostream &os) {
    do_display(os);
    return *this;
  }

  const Screen &display(std::ostream &os) const {
    do_display(os);
    return *this;
  }

 private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  mutable size_t access_ctr;
  // function to do the work of displaying a Screen
  void do_display(std::ostream &os) const { os << contents; }
};

class Window_mgr {
 private:
  std::vector<Screen> screens{Screen(24, 80, ' ')};
};

/**********************************************************
main function
**********************************************************/

int main() {
  Screen myscreen;
  char ch = myscreen.get();
  ch = myscreen.get(0, 0);

  Screen myScreen2(5, 3, ' ');
  const Screen blank(5, 3, ' ');
  myScreen2.set('#').display(cout);  // calls non const version
  blank.display(cout);               // calls const version

  return 0;
}

/**********************************************************
function definition
**********************************************************/

inline Screen &Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

// declared as inline in the class
char Screen::get(pos r, pos c) const {
  pos row = r * width;
  return contents[row + c];
}

void Screen::some_member() const { ++access_ctr; }

// function that return `*this`
inline Screen &Screen::set(char c) {
  contents[cursor] = c;  // set the new value at the current cursor location
  return *this;          // return this object as an lvalue
}

inline Screen &Screen::set(pos r, pos col, char ch) {
  contents[r * width + col] = ch;  // set specified location to given value
  return *this;                    // return this object as an lvalue
}

/*
Section 7.4 Class Scope
Section 7.5 Constructors Revisited
Section 7.6 static Class Members
*/