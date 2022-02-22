/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.43: Write a function that takes three strings, s, oldVal, and
newVal. Using iterators, and the insert and erase functions replace all
instances of oldVal that appear in s by newVal. Test your function by
using it to replace common abbreviations, such as “tho” by “though” and
“thru” by “through”.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.43.cpp

*/

#include <iostream>
#include <string>

void replaceStr(std::string &s, const std::string &oldVal,
                const std::string &newVal) {
  // Use `<` operator, because there is possibility that `it` jump over `end()`
  for (auto it = s.begin(); it < s.end() - oldVal.size() + 1;) {
    auto it2 = oldVal.cbegin();
    for (auto it3 = it; it2 != oldVal.cend(); ++it2, ++it3)
      if (*it3 != *it2) break;
    if (it2 == oldVal.cend()) {
      std::string::size_type pos = it - s.begin();
      s.erase(pos, oldVal.size());
      s.insert(pos, newVal);
      // Recalculate `it` from `begin()` rather than use `+=` operator, because
      // `it` is invalid by `erase()` and `insert()`
      it = s.begin() + pos + newVal.size();
    } else
      ++it;
  }
}

int main() {
  std::string s{"r u ok?\ngo thru\ntho tho altho\nthrough thruu"};

  std::cout << "Old:\n" << s << std::endl;
  replaceStr(s, "tho", "though");
  std::cout << "\nNew:\n" << s << std::endl;
  replaceStr(s, "thru", "through");
  std::cout << "\nNew:\n" << s << std::endl;
  replaceStr(s, "hl", "hello");
  std::cout << "\nNew:\n" << s << std::endl;
  replaceStr(s, "u", "you");
  std::cout << "\nNew:\n" << s << std::endl;

  return 0;
}