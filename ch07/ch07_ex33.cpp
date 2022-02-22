/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.33: What would happen if we gave Screen a size member
defined as follows? Fix any problems you identify.

    pos Screen::size() const{
      return height * width;
    }

Answer:

    Screen::pos Screen::size() const{
      return height * width;
    }

*/
