/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 13. Copy Control

13.1 Copy, Assign, and Destroy
  13.1.1 The Copy Constructor
************************************************/

/*
defining class:
  - copy constructor
  - copy-assignment operator
  - move constructor
  - move-assignment operator
  - destroy

https://www.programiz.com/cpp-programming/constructors

In which situations is the C++ copy constructor called?
https://stackoverflow.com/questions/21206359/in-which-situations-is-the-c-copy-constructor-called

Copy constructors
https://en.cppreference.com/w/cpp/language/copy_constructor
The copy constructor is called whenever an object is initialized
(by direct-initialization or copy-initialization)
from another object of the same type
(unless overload resolution selects a better match or the call is elided),
which includes
- initialization: T a = b; or T a(b);, where b is of type T;
- function argument passing: f(a);, where a is of type T and f is void f(T t);
- function return: return a; inside a function such as T f(),
where a is of type T, which has no move constructor.
*/

#include <iostream>
using namespace std;

// declare a class
class Wall {
 private:
  double length;
  double height;

 public:
  // default constructor
  Wall() {
    cout << "called default constructor" << endl;
    length = 10;
    height = 10;
  }
  // initialize variables with parameterized constructor
  Wall(double len, double hgt) {
    cout << "called parameterized constructor" << endl;
    length = len;
    height = hgt;
  }
  // copy constructor with a Wall object as parameter
  // copies data of the obj parameter
  Wall(Wall &obj) {
    cout << "called copy constructor" << endl;
    length = obj.length;
    height = obj.height;
  }
  double calculateArea() { return length * height; }
};

Wall ret_wall(Wall &wall) { return wall; }

int main() {
  // create an object of Wall class
  Wall wall1(10.5, 8.6);  // called parameterized ctor

  // copy contents of wall1 to wall2
  Wall wall2 = wall1;  // called copy ctor

  // print areas of wall1 and wall2
  cout << "Area of Wall 1: " << wall1.calculateArea() << endl;
  cout << "Area of Wall 2: " << wall2.calculateArea() << endl;

  // fx returning object
  cout << ret_wall(wall1).calculateArea() << endl;  // called copy ctor
  return 0;
}