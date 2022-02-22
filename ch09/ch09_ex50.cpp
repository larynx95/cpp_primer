/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.50: Write a program to process a vector<string>s whose
elements represent integral values. Produce the sum of all the elements in
that vector. Change the program so that it sums of strings that represent
floating-point values.

*/

#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> vs;
  for (std::string number; std::cin >> number; vs.push_back(number)) {
  }
  // int sum = 0;
  double sum = 0;
  for (const auto &s : vs)
    // sum += stoi(s);
    sum += stod(s);
  std::cout << "The sum is " << sum << std::endl;

  return 0;
}