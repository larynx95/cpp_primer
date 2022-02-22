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
7.3.3. Class Types (Exercises 7.31)
  - Class Declarations
7.3.4. Friendship Revisited
  - Friendship between Classes
  - Making A Member Function a Friend
  - Overloaded Functions and Friendship
  - Friend Declarations and Scope
*/

// https://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm

#include <iostream>
#include <vector>

using namespace std;

class Screen {
  // Window_mgr members can access the private parts of class Screen
  friend class Window_mgr;

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
  void do_display(std::ostream &os) const { os << contents; }
};

class Window_mgr {
 public:
  // location ID for each screen on the window
  using ScreenIndex = std::vector<Screen>::size_type;
  // reset the Screen at the given position to all blanks
  void clear(ScreenIndex);

 private:
  std::vector<Screen> screens{Screen(24, 80, ' ')};
};
void Window_mgr::clear(ScreenIndex i) {
  // s is a reference to the Screen we want to clear
  Screen &s = screens[i];
  // reset the contents of that Screen to all blanks
  s.contents = string(s.height * s.width, ' ');
};

int main() {
  //
  return 0;
}
/*
Section 7.4 Class Scope
Section 7.5 Constructors Revisited
Section 7.6 static Class Members
*/