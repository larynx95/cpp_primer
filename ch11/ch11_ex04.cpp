/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 11. Associative Containers

Exercise 11.4:
Extend your program to ignore case and punctuation.
For example,
“example.” “example,” and “Example” should all increment the same counter.
******************************************************************************/

#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

/*
https://github.com/fsaadatmand/Cpp-Primer
He uses some useful functions in standard libraries.
Very clever.
*/
void s_punctuation() {
  std::map<std::string, size_t> word_count;
  std::set<std::string> exclude = {"the", "but", "or", "an", "a"};
  std::string word;
  while (std::cin >> word) {
    if (word == "q") {
      break;
    }
    for (auto &c : word) {
      c = tolower(c);
    }
    if (ispunct(word.front())) word.erase(0, 1);
    if (ispunct(word.back())) word.pop_back();
    if (exclude.find(word) == exclude.end()) ++word_count[word];
  }
  for (const auto &w : word_count)
    std::cout << w.first << " occurs " << w.second
              << ((w.second > 1) ? " times" : " time") << std::endl;
}

/************************************************
Plan 1.
implementing 'contains' fx
find indices of punctuations
replace them with empty space

How to remove all the occurrences of a char in c++ string
https://stackoverflow.com/questions/20326356/how-to-remove-all-the-occurrences-of-a-char-in-c-string
************************************************/

template <typename T>
void print_vec(std::vector<T> vec) {
  for (auto iter = vec.begin(); iter != vec.end(); iter++) {
    std::cout << *iter << std::endl;
  }
}

int contains_chr(const char chr, const std::string &str) {
  for (auto elem : str) {
    if (chr == elem) return 1;
  }
  return 0;
}

int has_punctuation(const std::string &str) {
  std::string punc = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
  for (auto chr : punc) {
    if (str.find(chr) != std::string::npos) {
      return 1;
    }
  }
  return 0;
}

int is_contained(const char ch, const std::string &str) {
  for (auto elem : str) {
    if (elem == ch) {
      return 1;
    }
  }
  return 0;
}

int is_punctuation(const char chr) {
  return is_contained(chr, "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~");
}

std::vector<int> find_indices_contained(const std::string &str,
                                        const std::string &target) {
  std::vector<int> indices;
  for (int i = 0; i < str.size(); i++) {
    if (is_contained(str[i], target)) {
      indices.push_back(i);
    }
  }
  return indices;
}

std::string str_deleted_by_index(const std::string &str,
                                 std::vector<int> indices) {
  std::string new_str;
  int start_idx = 0;
  for (int i = 0; i < indices.size() + 1; i++) {
    std::string temp = str.substr(start_idx, indices[i] - start_idx);
    new_str += temp;
    start_idx = indices[i] + 1;
  }
  return new_str;
}

std::string get_str_without_punctuation(std::string &str) {
  std::string punctuations = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
  std::vector<int> indices = find_indices_contained(str, punctuations);
  std::string result;
  return str_deleted_by_index(str, indices);
}

/************************************************
Plan 2.
using useful standard library
************************************************/

// TODO: Find useful functions in STL, Boost ...

/************************************************
main
************************************************/
int main() {
  std::string origin = "Thi#s i&s a sa.mple te,xt with punct,uation.";
  std::cout << get_str_without_punctuation(origin) << std::endl;
  return 0;
}

/************************************************
references
************************************************/

/*
std::ispunct
https://en.cppreference.com/w/cpp/string/byte/ispunct

std::vector<T,Allocator>::front
https://en.cppreference.com/w/cpp/container/vector/front

std::vector<T,Allocator>::back
https://en.cppreference.com/w/cpp/container/vector/back

std::vector<T,Allocator>::pop_back
https://en.cppreference.com/w/cpp/container/vector/pop_back
*/