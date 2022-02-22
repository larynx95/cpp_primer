/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 3. Strings, Vectors, and Arrays

Section 3.1 Namespace using Declarations
Section 3.2 Library string Type
Section 3.3 Library vector Type
******************************************************************************/

#include <climits>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  /********************************************************
  3.3.1. Defining and Initializing vectors
  (Exercises 3.12 ~ 3.13)
  ********************************************************/

  /*
  https://en.cppreference.com/w/cpp/header/vector
  #include <vector>
  using std::vector;
  TODO: Vector vs. Array
  */

  // defining & initializing
  {
    vector<int> ivec;  // initially empty

    // give ivec some values
    vector<int> ivec2(ivec);      // copy elements of ivec into ivec2
    vector<int> ivec3 = ivec;     // copy elements of ivec into ivec3
    vector<vector<string>> file;  // vector of vectors
    // vector<string> svec(ivec2);  // error: svec holds strings, not ints

    vector<string> articles = {"a", "an", "the"};  // list initialization
    // vector<string> v2("a", "an", "the");  // error
  }

  // ways to initialize a vector
  {
      /*
      vector<T> v1          : empty vector holding objects of type T
      vector<T> v2(v1)      : v2 has a copy of each elements in v1
      vector<T> v2 = v1     : equivalent to above expression
      vector<T> v3(n, val)  : v3 has n elements with value val
      vector<T> v4(n)       : v4 has n copies of a value-initialized object
      vector<T> v5{a,b,c,...}    : v5 has as many elems as there are
      initializers vector<T> v5 = {a,b,c,...} : equivalent to above expression
      */
  }

  // list initialization
  {
    vector<string> articles = {"a", "an", "the"};  // list initialization

    // use curly braces, not parentheses
    vector<string> v1{"a", "an", "the"};
    // vector<string> v1("a", "an", "the");
  }

  // value initialization
  {
    vector<int> ivec4(10);     // ten elements, each initialized to 0
    vector<string> svec4(10);  // ten elements, each an empty string

    vector<int> v1(10);     // v1 has ten elements with value 0
    vector<int> v2{10};     // v2 has one element with value 10
    vector<int> v3(10, 1);  // v3 has ten elements with value 1
    vector<int> v4{10, 1};  // v4 has two elements with values 10 and 1

    vector<string> v5{"hi"};  // list initialization: v5 has one element
    // vector<string> v6("hi");
    // error: can't construct a vector from a string literal
    vector<string> v7{10};        // v7 has ten default-initialized elements
    vector<string> v8{10, "hi"};  // v8 has ten elements with value "hi"
  }

  /********************************************************
  3.3.2. Adding Elements to a vector
  ********************************************************/

  // add elems to vector with fixed length (or size)
  {
    vector<int> vec;  // empty vector
    for (int i = 0; i < 3; ++i)
      vec.push_back(i);  // append sequential integers to vec
                         // at end of loop vec has 3 elements, values 0 . . . 99

    for (int i = 0; i < 3; i++) {
      cout << vec[i] << " ";
    }
    cout << endl;
  }

  // vector with unknown length (or size) until runtime
  {
    string word;
    vector<string> text;  // empty vector
    int i = 0;
    cout << "Enter a word: ";
    while (cin >> word) {
      text.push_back(word);
      // append word to text
      i++;
      if (i >= 3) break;
      cout << "Enter a word: ";
    }

    // TODO: Why? How?
    // The standard requires that vector implementations can efficiently add
    // elements at run time. Because vectors grow efficiently, it is often
    // unnecessary—and can result in poorer performance—to define a vector of a
    // specific size. The exception to this rule is if all the elements actually
    // need the same value.
  }

  /********************************************************
  3.3.3. Other vector Operations
  (Exercises 3.16 ~ 3.20)
  ********************************************************/

  // vector operations
  {
    /*
       v.empty()        : return true if v is empty
       v.size()         : return the number of lements in v
       v.push_back(t)   : add an number, append not prepend
       v[n]             : return a reference to the element
       v1 = v2          : replace the elems in v1 with a copy of v2
       v1 = {a,b,c,...} : replace the elems in v1 with a copy list
       v1 == v2 v1 != v2 : compare size and each elem
       <, <=, >, >=     : comapre

       // vector type always includes its element type
       vector<int>::size_type  // ok
       vector::size_type       // error
     */

    vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i : vec)  // for each element in vec (note: i is a reference)
      i *= i;            // square the element value
    for (auto i : vec)   // for each element in vec
      cout << i << " ";  // print the element
    cout << endl;
  }

  // computing a vector index
  {
      // TODO: What is this?
      /*
      // count the number of grades by clusters of three:
      // 0--9, 10--19, 20--29
      vector<unsigned> scores(3, 0);  // 3 buckets, all initially 0
      unsigned grade;
      while (cin >> grade) {    // read the grades
        if (grade <= 100)       // handle only valid grades
          ++scores[grade / 3];  // increment the counter for the current cluster
      }
      */
  }

  // Indexing (subscripting) vs. push_back()
  {
    vector<int> ivec;  // empty vector

    /*
    // TODO: Error!
    // The subscript operator on vector (and string)
    // fetches an existing element;
    // it does NOT add an element.
    for (decltype(ivec.size()) ix = 0; ix != 5; ++ix)
      ivec[ix] = ix;  // disaster: ivec has no elements
    */

    for (decltype(ivec.size()) ix = 0; ix != 5; ++ix)
      ivec.push_back(ix);  // ok: adds a new element with value ix

    for (decltype(ivec.size()) ix = 0; ix != 5; ++ix) {
      cout << ivec[ix] << " ";
    }
    cout << endl;
  }

  // indexing
  {
    vector<int> ivec6;  // empty vector
    // cout << ivec6[0];       // error: ivec has no elements!
    vector<int> ivec7(10);  // vector with ten elements
    // cout << ivec7[10];      // error: ivec2 has elements 0 . . . 9
  }

  return 0;
}

/*
Section 3.4 Introducing Iterators
Section 3.5 Arrays
Section 3.6 Multidimensional Arrays
*/