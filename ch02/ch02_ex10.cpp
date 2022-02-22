/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Exercise 2.10: What are the initial values, if any, of each of the following
variables?

    std::string global_str;
    int global_int;
    int main() {
        int local_int;
        std::string local_str;
    }

*/

#include <iostream>

std::string global_str;  // Empty string object
int global_int;          // 0
int main() {
  int local_int;          // Undefined value
  std::string local_str;  // Empty string object

  std::cout << local_int << " " << local_str << std::endl;

  return 0;
}