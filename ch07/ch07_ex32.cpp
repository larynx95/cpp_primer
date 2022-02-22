/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.32: Define your own versions of Screen and Window_mgr in
which clear is a member of Window_mgr and a friend of Screen.

https://github.com/chihyang/CPP_Primer/tree/master/chap07
https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.32.cpp
*/

#include <iostream>
#include <string>
#include <vector>

/**********************************************************
 * class definition, prototypes
 **********************************************************/

class Window_mgr;
class Screen;

class Window_mgr {
 public:
  using ScreenIndex = std::vector<Screen>::size_type;
  void clear(ScreenIndex);
  Window_mgr() = default;
  Window_mgr(const Screen& s);
  const Screen& get(ScreenIndex i) const { return screens[i]; }

 private:
  std::vector<Screen> screens;  //{Screen(24, 80, ' ')};
};

class Screen {
  friend void Window_mgr::clear(ScreenIndex);

 public:
  using pos = std::string::size_type;
  Screen() = default;
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  char get() const { return contents[cursor]; }
  inline char get(pos ht, pos wd) const;
  Screen& move(pos r, pos c);
  Screen& set(pos row, pos col, char c);
  Screen& set(char c);
  Screen& display(std::ostream& os);
  const Screen& display(std::ostream& os) const;

 private:
  void do_display(std::ostream& os) const;
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

/**********************************************************
 * main function
 **********************************************************/

int main() {
  Screen s(24, 80, 'x');
  Window_mgr win(s);
  std::cout << "The original win:" << std::endl;
  win.get(0).display(std::cout);
  std::cout << std::endl;
  win.clear(0);
  std::cout << "The cleared win:" << std::endl;
  win.get(0).display(std::cout);
  return 0;
}

/**********************************************************
 * function definitions
 **********************************************************/

char Screen::get(pos ht, pos wd) const {
  pos row = wd * width;
  return contents[row + ht];
}

Screen& Screen::move(pos r, pos c) {
  cursor = r * width + c;
  return *this;
}

Screen& Screen::set(pos row, pos col, char c) {
  contents[row * width + col] = c;
  return *this;
}

Screen& Screen::set(char c) {
  contents[cursor] = c;
  return *this;
}

Screen& Screen::display(std::ostream& os) {
  do_display(os);
  return *this;
}

const Screen& Screen::display(std::ostream& os) const {
  do_display(os);
  return *this;
}

inline void Screen::do_display(std::ostream& os) const { os << contents; }
Window_mgr::Window_mgr(const Screen& s) { screens = {s}; }

// friend function clear()
void Window_mgr::clear(ScreenIndex i) {
  if (i < screens.size()) {
    Screen& s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
  }
}