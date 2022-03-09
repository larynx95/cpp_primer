/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 05. Statements

Exercise 5.21: Revise the program from the exercise in § 5.5.1 (p. 191) so
that it looks only for duplicated words that start with an uppercase letter.

*/

#include <iostream>
#include <string>

int main() {
  std::string word, prevWord;
  bool match = false;

  while (std::cin >> word) {
    if (!isupper(word[0])) continue;

    if (!prevWord.empty() && word == prevWord) {
      match = true;
      break;
    }
    prevWord = word;
  }

  if (match)
    std::cout << word << '\n';
  else
    std::cout << "no word was repeated\n";

  return 0;
}
