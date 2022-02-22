/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.24: Our program that distinguished between high pass, pass,
and fail depended on the fact that the conditional operator is right
associative. Describe how that operator would be evaluated if the operator
were left associative.

Answer:
If the operator were left associative, then the expression

grade > 90 ? "high pass"
           : grade < 60 ? "fail" : "pass";
would be evaluated as:

(grade > 90 ? "high pass" : grade < 60) ? "fail" : "pass";
which means:

if the grade is greater than 90, then return "high pass", which is not empty
string and evaluate to true, then return "fail"; else evaluates grade < 60 and
takes the result as the condition for the second conditional operator, which
means if the grade is less than 60, return "fail", else return "pass".

*/

#include <string>
using std::string;

int main() {
  //

  return 0;
}