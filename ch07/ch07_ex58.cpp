/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.58: Which, if any, of the following static data member
declarations and definitions are errors? Explain why.
*/

#include <iostream>
#include <vector>

using std::vector;

class Example {
 public:
  static double rate;
  static const int vecSize = 20;
  static vector<double> vec;
};

double Example::rate = 6.5;
vector<double> Example::vec(vecSize);
int main() { return 0; }