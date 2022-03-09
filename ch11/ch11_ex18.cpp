/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 11. Associative Containers

Exercise 11.18:
Write the type of map_it from the loop on page 430
without using auto or decltype.
******************************************************************************/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  std::map<std::string, size_t> word_count{{"Moon Jae Ang", 18},
                                           {"Nho Mu Hyun", 18}};
  std::map<std::string, size_t>::const_iterator map_it = word_count.cbegin();
  while (map_it != word_count.cend()) {
    cout << map_it->first << " occurs " << map_it->second << " times" << endl;
    ++map_it;
  }
}