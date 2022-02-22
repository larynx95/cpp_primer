/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.33: Using Table 4.12 (p. 166) explain what the following
expression does:

someValue ? ++x, ++y : --x, --y

Answer:
The expression

sameValue ? ++x, ++y : --x, --y
is the same as

(sameValue ? (++x, ++y) : --x), --y
Then it will be easy to notice that whatever sameValue evaluated, --y will
always be evaluated.
*/

int main() {
  //

  return 0;
}