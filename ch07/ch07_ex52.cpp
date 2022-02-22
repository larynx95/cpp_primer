/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.52: Using our first version of Sales_data from § 2.6.1 (p. 72),
explain the following initialization. Identify and fix any problems.

Sales_data item = {"978-0590353403", 25, 15.99};

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.52.cpp
*/

#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  unsigned units_sold;  //= 0;
  double revenue;       //= 0.0;
  // Error: Cannot provide in-class initializer for an aggregate class
  // (since C++11) (until C++14)
};

int main() {
  Sales_data item = {"978-0590353403", 25, 15.99};

  return 0;
}