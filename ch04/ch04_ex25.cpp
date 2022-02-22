/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 04. Expressions

Exercise 4.25: What is the value of ~'q' << 6 on a machine with 32-bit
ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the
bit pattern 01110001?

Answer:
~'q' << 6 is the same as (~'q') << 6.

The operand of ~ operator is a "small integer"(char here), thus its value is
first promoted to a larger integral type(int here).

'q' = 01110001 promoted to 00000000 00000000 00000000 01110001

After the ~ operator evaluated,

~'q' 11111111 11111111 11111111 10001110

Left shift,

~'q' << 6 11111111 11111111 11100011 10000000

The result is -7296.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch4/4.25.md

*/

#include <string>
using std::string;

int main() {
  //

  return 0;
}