/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 05. Statements

Exercise 5.3: Use the comma operator (§ 4.10, p. 157) to rewrite the
while loop from § 1.4.1 (p. 11) so that it no longer requires a block. Explain
whether this rewrite improves or diminishes the readability of this code.

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