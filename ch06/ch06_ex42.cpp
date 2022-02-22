/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.42: Give the second parameter of make_plural (§ 6.3.2, p.
224) a default argument of 's'. Test your program by printing singular and
plural versions of the words success and failure.

*/

#include <iostream>
#include <string>

std::string make_plural(size_t ctr, const std::string &word,
                        const std::string &ending = "s") {
  return (ctr > 1) ? word + ending : word;
}

int main() {
  std::cout << "success: " << make_plural(2, "success", "es") << std::endl;
  std::cout << "failure: " << make_plural(2, "failure") << std::endl;

  return 0;
}