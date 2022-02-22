/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Section 10.1 Overview
Section 10.2 A First Look at the Algorithms
Section 10.3 Customizing Operations
******************************************************************************/

/*
10.3.1. Passing a Function to an Algorithm
- Predicates
- Sorting Algorithms
10.3.2. Lambda Expressions
- Introducing Lambdas
  [capture list] (parameter list) -> return type { function body }
- Passing Arguments to a Lambda
- Using the Capture List
- Calling find_if
- The for_each Algorithm
- Putting It All Together

10.3.3. Lambda Captures and Returns
- Capture by Value

  []                    empty capture list
  [names]               names is a comma-separated list of names
  [&]                   implicit by reference capture list
  [=]                   implicit by value capture list
  [&, identifier_list]  ...
  [=, reference_list]   ...

- Capture by Reference
- Implicit Captures
- Mutable capture
- Specifying the Lambda Return Type

10.3.4. Binding Arguments
- The Library bind Function
- Binding the sz Parameter of check_size
- Using placeholders Names
- Arguments to bind
- Using to bind to Reorder Parameters
- Binding Reference Parameters

*/

#include <algorithm>
#include <iostream>
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

// comparison function to be used to sort by word length
bool isShorter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}

inline string make_plural(size_t ctr, const string &word,
                          const string &ending) {
  return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
  elimDups(words);  // put words in alphabetical order and  duplicates
  // sort words by size, but maintain alphabetical order for words of the
  // same size
  stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
    return a.size() < b.size();
  });
  // get an iterator to the first element whose size() is >= sz
  auto wc = find_if(words.begin(), words.end(),
                    [sz](const string &a) { return a.size() >= sz; });
  // compute the number of elements with size >= sz
  auto count = words.end() - wc;
  cout << count << " " << make_plural(count, "word", "s") << " of length " << sz
       << " or longer" << endl;
  // print words of the given size or longer, each one followed by a space
  for_each(wc, words.end(), [](const string &s) { cout << s << " "; });
  cout << endl;
}

void fcn1() {
  size_t v1 = 42;  // local variable
  // copies v1 into the callable object named f
  auto f = [v1] { return v1; };
  v1 = 0;
  auto j = f();  // j is 42; f stored a copy of v1 when we created it
}

void fcn2() {
  size_t v1 = 42;  // local variable
  // the object f2 contains a reference to v1
  auto f2 = [&v1] { return v1; };
  v1 = 0;
  auto j = f2();  // j is 0; f2 refers to v1; it doesn't store it
}

void fcn3() {
  size_t v1 = 42;  // local variable
  // f can change the value of the variables it captures
  auto f = [v1]() mutable { return ++v1; };
  v1 = 0;
  auto j = f();  // j is 43
}

void fcn4() {
  size_t v1 = 42;  // local variable
  // v1 is a reference to a non const variable
  // we can change that variable through the reference inside f2
  auto f2 = [&v1] { return ++v1; };
  v1 = 0;
  auto j = f2();  // j is 1
}

int main() {
  // sort on word length, shortest to
  vector<string> svec = {"I", "am", "alive"};
  sort(svec.begin(), svec.end(), isShorter);

  stable_sort(svec.begin(), svec.end(), isShorter);
  for (const auto &s : svec)  // no need to copy the strings
    cout << s << " ";         // print each element separated by a space
  cout << endl;

  // sort svec by size, but maintain alphabetical order for svec of the same
  // size
  stable_sort(svec.begin(), svec.end(), [](const string &a, const string &b) {
    return a.size() < b.size();
  });

  // get an iterator to the first element whose size() is >= sz
  auto wc = find_if(svec.begin(), svec.end(),
                    [](const string &a) { return a.size() >= 2; });

  return 0;
}

/*
Section 10.4 Revisiting Iterators
Section 10.5 Structure of Generic Algorithms
Section 10.6 Container-Specific Algorithms
*/