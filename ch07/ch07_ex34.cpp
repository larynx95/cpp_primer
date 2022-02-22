/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.34: What would happen if we put the typedef of pos in the
Screen class on page 285 as the last line in the class?

https://github.com/chihyang/CPP_Primer/blob/master/chap07/Exer07_34.cpp
*/

#include <iostream>
#include <string>

int height;
class Screen {
 public:
  void dummy_fcn(pos height) { cursor = witdh * height; }

 private:
  pos cursor = 0;
  pos height = 0, width = 0;
  typedef std::string::size_type pos;
};
int main() { return 0; }