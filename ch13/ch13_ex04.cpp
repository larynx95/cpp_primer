/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 13. Copy Control

Exercise 13.4:
Assuming Point is a class type with a public copy constructor, identify each
use of the copy constructor in this program fragment:

Point global;
Point foo_bar(Point arg)
{
  Point local = arg, *heap = new Point(global);
  *heap = local;
  Point pa[ 4 ] = { local, *heap };
  return *heap;
}

************************************************/

#include <iostream>
#include <vector>

int main() {
  //
  return 0;
}