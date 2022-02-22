/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.10: What are the types of the following four objects?

    vector<int> v1;
    const vector<int> v2;
    auto it1 = v1.begin(), it2 = v2.begin();
    auto it3 = v1.cbegin(), it4 = v2.cbegin();

*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  vector<int> v1;
  const vector<int> v2;
  // auto it1 = v1.begin(), it2 = v2.begin();
  // it1 and it2 have different type, thus need be seperated into two
  // statements.
  auto it1 = v1.begin();
  // the type of `it1` is `vector<int>::iterator`
  auto it2 = v2.begin();
  // the type of `it2` is `vector<int>::const_iterator`
  auto it3 = v1.cbegin(), it4 = v2.cbegin();
  // the type of `it3` and `it4` is `vector<int>::const_iterator`

  return 0;
}
