/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 11. Associative Containers

Exercise 11.28:
Define and initialize a variable to hold the result of calling find on a
map from string to vector of int.
******************************************************************************/

#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  std::map<std::string, std::vector<int>> words{{"open", {5, 9, 10}},
                                                {"door", {8, 1}},
                                                {"car", {4}},
                                                {"black", {3, 8, 9, 6}}};
  auto doorVar = *words.find("door");  // dereference the returned value
  std::cout << doorVar.first << ": ";
  for (const auto &elem : doorVar.second) std::cout << elem << ' ';
  std::cout << std::endl;
  return 0;
}
