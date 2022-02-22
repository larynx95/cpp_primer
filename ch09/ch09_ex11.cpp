/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.11: Show an example of each of the six ways to create and
initialize a vector. Explain what values each vector contains.

*/

#include <vector>
using std::vector;

int main() {
  vector<int> v1;                        // Empty
  vector<int> v2(v1);                    // Empty
  vector<int> v3 = v1;                   // Empty
  vector<int> v4{1, 2, 3};               // 3 elements: 1, 2, 3
  vector<int> v5 = {1, 2, 3};            // 3 elements: 1, 2, 3
  vector<int> v6(v5.begin(), v5.end());  // 3 elements: 1, 2, 3

  vector<int> v7(5);     // 5 elements: 0, 0, 0, 0, 0
  vector<int> v8(5, 1);  // 5 elements: 1, 1, 1, 1, 1

  return 0;
}