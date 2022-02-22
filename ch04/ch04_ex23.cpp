/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.23: The following expression fails to compile due to operator
precedence. Using Table 4.12 (p. 166), explain why it fails. How would you
fix it?

string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;

*/

#include <string>
using std::string;

int main() {
  string s = "word";
  // string pl = s + s[s.size() - 1] == 's' ? "" : "s";
  string pl = s + (s[s.size() - 1] == 's' ? "" : "s");

  // The precedence of the conditional operator is lower than arithmetic
  // operator.

  return 0;
}