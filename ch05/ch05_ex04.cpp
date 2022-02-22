/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 05. Statements

Exercise 5.4: Explain each of the following examples, and correct any
problems you detect.
(a) while (string::iterator iter != s.end()) { // ... }
(b) while (bool status = find(word)) { //... }
if (!status) { //...  }

*/

#include <iostream>

int main() {
  int sum = 0, val = 1;
  // while (val <= 10 && (sum += val++)) ;  // null statement
  while (val <= 10 && (sum += val, ++val))
    ;  // null statement
  std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

  // I think this rewrite diminishes the readability of the code.

  return 0;
}