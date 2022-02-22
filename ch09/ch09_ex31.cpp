/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.31: The program on page 354 to remove even-valued elements
and duplicate odd ones will not work on a list or forward_list. Why?
Revise the program so that it works on these types as well.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.31.cpp

*/

#include <forward_list>
#include <iostream>
#include <list>

void change(std::list<int> &li) {
  for (auto iter = li.begin(); iter != li.end();)
    if (*iter % 2) {
      iter = li.insert(iter, *iter);
      ++iter;
      ++iter;
      // iter += 2;  // Error: list doesn't support iterator arithmetic
    } else
      iter = li.erase(iter);
}

void change(std::forward_list<int> &fli) {
  for (auto pre = fli.before_begin(), cur = fli.begin(); cur != fli.end();) {
    if (*cur % 2) {
      pre = fli.insert_after(pre, *cur);
      ++pre;
      ++cur;
    } else
      cur = fli.erase_after(pre);
  }
}

int main() {
  std::list<int> li{1, 2, 3, 4, 5, 6};
  std::forward_list<int> fli{1, 2, 3, 4, 5, 6};

  std::cout << "li:\n";
  for (const auto &i : li) std::cout << i << " ";
  std::cout << std::endl;

  change(li);

  for (const auto &i : li) std::cout << i << " ";
  std::cout << std::endl;

  std::cout << "fli:\n";
  for (const auto &i : fli) std::cout << i << " ";
  std::cout << std::endl;

  change(fli);

  for (const auto &i : fli) std::cout << i << " ";
  std::cout << std::endl;

  return 0;
}