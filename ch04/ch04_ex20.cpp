/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.20: Assuming that iter is a vector<string>::iterator,
indicate which, if any, of the following expressions are legal. Explain the
behavior of the legal expressions and why those that aren’t legal are in error.
(a) *iter++;
(b) (*iter)++;
(c) *iter.empty()
(d) iter->empty();
(e) ++*iter;
(f) iter++->empty();

Answer:
https://en.cppreference.com/w/cpp/string/basic_string

(a) *iter++; is legal. The expression moves iter to point to the next element
and returns the value of the original element.

(b) (*iter)++ is not legal. The expression means increasing value of the
element, but the value is a string and string does not have ++ operator.

(c) *iter.empty() is not legal. Because iter is an iterator and has no member
named empty.

(d) iter->empty() is legal. The expression means check if the string pointed by
iter is empty.

(e) ++*iter is not legal. The expression means increasing value of the element,
but the value is a string and string does not have ++ operator.

(f) iter++->empty() is legal. The expression means move iter to point to the
next element and check if that string is empty.

*/

#include <iostream>

int main() {
  //

  return 0;
}