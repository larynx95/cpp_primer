/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.18: Write a program to read a sequence of strings from the
standard input into a deque. Use iterators to write a loop to print the
elements in the deque.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch9/9.18.cpp

*/

#include <deque>
#include <iostream>
#include <string>

int main() {
  std::deque<std::string> words;
  std::string word;
  while (std::cin >> word) words.push_back(word);

  for (std::deque<std::string>::const_iterator it = words.cbegin();
       it != words.cend(); ++it)
    std::cout << *it << std::endl;

  for (std::deque<std::string>::const_iterator it = words.cbegin();
       it != words.cend();)
    std::cout << *(it++) << std::endl;

  return 0;
}