/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.34: Assuming vi is a container of ints that includes even and
odd values, predict the behavior of the following loop. After you’ve analyzed
this loop, write a program to test whether your expectations were correct.

iter = vi.begin();
while (iter != vi.end())
  if (*iter % 2)
    iter = vi.insert(iter, *iter);
  ++iter;

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.34.cpp

*/

#include <vector>

int main() {
  // std::vector<int> vi{1, 2, 3, 4};
  std::vector<int> vi{2, 4};

  // If the container contains any odd values, the loop will continue
  // infinitely.
  auto iter = vi.begin();
  while (iter != vi.end()) {  // The loop body should be a block.
    if (*iter % 2) iter = vi.insert(iter, *iter);
    ++iter;
  }

  return 0;
}