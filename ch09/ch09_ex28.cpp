/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.28: Write a function that takes a forward_list<string> and
two additional string arguments. The function should find the first string
and insert the second immediately following the first. If the first string is
not found, then insert the second string at the end of the list.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.28.cpp

*/

#include <forward_list>
#include <iostream>
#include <string>

void insertAfterStr(std::forward_list<std::string> &fls, const std::string &s1,
                    const std::string &s2) {
  auto pre = fls.before_begin();
  auto cur = fls.begin();
  while (cur != fls.end()) {
    if (*cur == s1) {
      fls.insert_after(cur, s2);
      return;
    } else {
      pre = cur++;
    }
  }
  fls.insert_after(pre, s2);
}

int main() {
  std::forward_list<std::string> fls{"s1", "s2", "s3"};

  for (const auto &s : fls) std::cout << s << " ";
  std::cout << std::endl;

  insertAfterStr(fls, "s2", "s4");

  for (const auto &s : fls) std::cout << s << " ";
  std::cout << std::endl;

  insertAfterStr(fls, "s5", "s6");

  for (const auto &s : fls) std::cout << s << " ";
  std::cout << std::endl;

  return 0;
}