/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Section 10.1 Overview
Section 10.2 A First Look at the Algorithms
******************************************************************************/

/*
10.2.1. Read-Only Algorithms
- Algorithms and Element Types
- Algorithms That Operate on Two Sequences

10.2.2. Algorithms That Write Container Elements
- Algorithms Do Not Check Write Operations
- Introducing back_inserter
- Copy Algorithms

10.2.3. Algorithms That Reorder Container Elements
- Eliminating Duplicates
- using unique
- Using Container Operations to Remove Elements

*/

#include <algorithm>
#include <iostream>
#include <numeric> /* for accumulate */
#include <vector>
using namespace std;

void elimDups(vector<string> &words) {
  // sort words alphabetically so we can find the duplicates
  sort(words.begin(), words.end());
  // unique reorders the input range so that each word appears once in the
  // front portion of the range and returns an iterator one past the unique
  // range
  auto end_unique = unique(words.begin(), words.end());
  // erase uses a vector operation to remove the nonunique elements
  words.erase(end_unique, words.end());
}

int main() {
  vector<int> vi1 = {0, 1, 2, 3, 4};
  vector<string> vs1 = {"abc", "def", "ghi"};

  // sum the elements in vec starting the summation with the value 0
  int sum_vi1 = accumulate(vi1.cbegin(), vi1.cend(), 100);
  string sum_vs1 = accumulate(vs1.cbegin(), vs1.cend(), string(""));
  cout << "sum of integer vector vi1 is " << sum_vi1 << endl;
  cout << "sum of string vector vs1 is " << sum_vs1 << endl;

  vector<int> vec;                     // empty vector
  fill_n(vec.begin(), vec.size(), 0);  // reset all the elements of vec to  0
  // disaster: attempts to write to ten (nonexistent) elements in vec
  // fill_n(vec.begin(), 10, 0);

  int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int a2[sizeof(a1) / sizeof(*a1)];  // a2 has the same size as a1
  // ret points just past the last element copied into a2
  auto ret = copy(begin(a1), end(a1), a2);  // copy a1 into a2

  // replace any element with the value 0 with 42
  vector<int> ilst = {0, 1, 2, 0, 4, 5};
  replace(ilst.begin(), ilst.end(), 0, 42);
  cout << ilst[0] << " " << ilst[3] << endl;

  // replace_copy
  int myints[] = {10, 20, 30, 15, 20, 10, 10, 20};
  vector<int> myvector(8);
  replace_copy(myints, myints + 8, myvector.begin(), 20, 99);
  cout << "myvector contains:";
  for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    cout << ' ' << *it;
  cout << '\n';

  // unique
  vector<string> svec = {"a", "a", "c", "b", "b"};
  elimDups(svec);

  return 0;
}

/*
Section 10.3 Customizing Operations
Section 10.4 Revisiting Iterators
Section 10.5 Structure of Generic Algorithms
Section 10.6 Container-Specific Algorithms
*/