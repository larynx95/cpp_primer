/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Exercise 9.6: What is wrong with the following program? How might you
correct it?

    list<int> lst1;
    list<int>::iterator iter1 = lst1.begin(),
    iter2 = lst1.end();
    while (iter1 < iter2) // ...

*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  list<int> lst1 = {7, 5, 16, 8};
  list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
  while (iter1 != iter2) {
    printf("%d ", *iter1);
    iter1++;
  }

  return 0;
}
