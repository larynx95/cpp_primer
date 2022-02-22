/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 03. Strings, Vectors, and Arrays

Exercise 3.28: What are the values in the following arrays?

    string sa[10];
    int ia[10];
    int main() {
      string sa2[10];
      int ia2[10];
    }

******************************************************************************/

#include <string>
using std::string;

string sa[10];  // ten elements of empty string
int ia[10];     // ten elements of 0

int main() {
  string sa2[10];  // ten elements of empty string
  int ia2[10];     // ten elements of undefined value
}