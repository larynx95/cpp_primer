/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 7. Classes

Section 7.1 Defining Abstract Data Types
Section 7.2 Access Control and Encapsulation
Section 7.3 Additional Class Features
******************************************************************************/

/*
7.3.1. Class Members Revisited
- Defining a Type Member

    ```cpp
    class Screen {
    public:
      typedef std::string::size_type pos;
    private:
      pos cursor = 0;
      pos height = 0, width = 0;
      std::string contents;
    };
    ```

    ```cpp
    class Screen {
    public:
      // alternative way to declare a type member using a type alias
      using pos = std::string::size_type;
      // other members as before
    };
    ```
- Member Functions of class Screen

    ```cpp
    class Screen {
    public:
      typedef std::string::size_type pos;
      Screen() = default; // needed because Screen has another constructor
      // cursor initialized to 0 by its in-class initializer
      Screen(pos ht, pos wd, char c): height(ht), width(wd),
      contents(ht * wd, c) { }
      char get() const               // get the character at the cursor
        { return contents[cursor]; } // implicitly inline
      inline char get(pos ht, pos wd) const; // explicitly inline
      Screen &move(pos r, pos c);   // can be made inline later
    private:
      pos cursor = 0;
      pos height = 0, width = 0;
      std::string contents;
    };
    ```
- Making Members inline
  TODO: member functions defined inside the class are automatically inline?

    ```cpp
    inline // we can specify inline on the definition
    Screen &Screen::move(pos r, pos c){
      pos row = r * width; // compute the row location
      cursor = row + c ; // move cursor to the column within that row
      return *this; // return this object as an lvalue
    }

    // declared as inline in the class
    char Screen::get(pos r, pos c) const
    {
      pos row = r * width; // compute row location
      return contents[row + c]; // return character at the given column
    }
    ```

- Overloading Member Functions

- mutable Data Members
  never const, even when it is a member of a const object

    ```cpp
    class Screen {
    public:
      void some_member() const;
    private:
      mutable size_t access_ctr; // may change even in a const object
      // other members as before
    };

    void Screen::some_member() const {
      ++access_ctr; // keep a count of the calls to any member function
      // whatever other work this member needs to do
    }
    ```

- Initializers for Data Members of Class Type

    ```cpp
    class Window_mgr {
    private:
      // Screens this Window_mgr is tracking
      // by default, a Window_mgr has one standard sized blank Screen
      std::vector<Screen> screens{Screen(24, 80, ' ') };
    };
    ```

7.3.2. Functions That Return *this

    ```cpp
    class Screen {
    public:
      Screen &set(char);
      Screen &set(pos, pos, char);
      // other members as before
    };

    inline Screen &Screen::set(char c){
      contents[cursor] = c; // set the new value at the current cursor location
      return *this; // return this object as an lvalue
    }

    inline Screen &Screen::set(pos r, pos col, char ch){
      contents[r*width + col] = ch; // set specified location to given
      value
      return *this; // return this object as an lvalue
    }
```

- Returning *this from a const Member Function (TODO:)

    ```cpp
    class Screen {
    public:
      // display overloaded on whether the object is const or not
      Screen &display(std::ostream &os) { do_display(os); return *this; }
      const Screen &display(std::ostream &os) const {
        do_display(os); return *this;
      }
    private:
      // function to do the work of displaying a Screen
      void do_display(std::ostream &os) const {os << contents;}
      // other members as before
    };
    ```

- Overloading Based on const

7.3.4. Friendship Revisited

- Friendship between Classes
  Screen class want to be a friend with Window_mgr

    ```cpp
    class Screen {
      // Window_mgr members can access the private parts of class Screen
      friend class Window_mgr;
      // ... rest of the Screen class
    };
    ```

- Window_mgr is a friend of Screen, we can write the clear member of Window_mgr

    ```cpp
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
      s.contents = string(s.height * s.width, ' ');  // TODO: string()?
    }
    ```

- Making A Member Function a Friend

    ```cpp
    class Screen {
      // Window_mgr::clear must have been declared before class Screen
      friend void Window_mgr::clear(ScreenIndex);
      // ... rest of the Screen class
    };
    ```

- Overloaded Functions and Friendship

    ```cpp
    // overloaded storeOn functions
    extern std::ostream& storeOn(std::ostream &, Screen &);
    extern BitMap& storeOn(BitMap &, Screen &);

    class Screen {
      // ostream version of storeOn may access
      // the private parts of Screen objects
      friend std::ostream& storeOn(std::ostream &, Screen &);
      // . . .
    };
    ```

*/

// https://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm

#include <iostream>

using namespace std;

class Box {
  double width;

 public:
  friend void printWidth(Box box);
  void setWidth(double wid);
};

// Member function definition
void Box::setWidth(double wid) { width = wid; }

// Note: printWidth() is not a member function of any class.
void printWidth(Box box) {
  /* Because printWidth() is a friend of Box, it can
  directly access any member of this class */
  cout << "Width of box : " << box.width << endl;
}

// Main function for the program
int main() {
  Box box;             // set box width without member function
  box.setWidth(10.0);  // Use friend function to print the wdith.
  printWidth(box);
  return 0;
}

/*
Section 7.4 Class Scope
Section 7.5 Constructors Revisited
Section 7.6 static Class Members
*/