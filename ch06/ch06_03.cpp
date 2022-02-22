/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 6. Functions

Section 6.1 Function Basics
Section 6.2 Argument Passing
Section 6.3 Return Types and the return Statement
******************************************************************************/

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

typedef int arrT[10];  // arrT is a synonym for the type array of ten ints
// using arrtT = int[10];  // equivalent declaration of arrT; 2.5.1 (p.68)
arrT *func(int i);  // func returns a pointer to an array of five ints

string make_plural(size_t ctr, const string &word, const string &ending);
const string &shorterString(const string &s1, const string &s2);
char &get_val(string &str, string::size_type ix);
int (*fx_ret_ptr(int i))[10];
auto func2(int i) -> int (*)[10];
vector<string> process();
int factorial(int val);

// returns a pointer to an array of five int elements
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
decltype(odd) *arrPtr(int i) {
  return (i % 2) ? &odd : &even;  // returns a pointer to the array
}

int main() {
  /********************************************************
  6.3.1. Functions with No Return Value
  ********************************************************/

  int x = 100;
  int y = 200;
  swap(x, y);
  cout << "x: " << x << ", y: " << y << endl;

  /********************************************************
  6.3.2. Functions That Return a Value
  (Exercises 6.30 ~ 6.35)
  ********************************************************/

  // How Values Are Returned
  {
    // Values are returned in exactly the same way as variables
    // and parameters are initialized:
    // The return value is used to initialize a temporary at the call site,
    // and that temporary is the result of the function call.

    cout << make_plural(2, "EarPieceFather", "s") << endl;
    cout << shorterString("MoonJaeAng", "KimJungSook") << endl;
  }

  // Never Return a Reference or Pointer to a Local Object
  {
      /*
      const string &manip(){
        string ret;
        // transform ret in some way
        if (!ret.empty())
          return ret;  // WRONG: returning a reference to a local object!
        else
          return "Empty";  // WRONG: "EMpty" is a local temporary string
      }
      */
  }

  // Functions That Return Class Types and the Call Operator
  {
    // string class
    auto sz = shorterString("Woohan", "Disaster").size();  // rvalue
    cout << typeid(sz).name() << endl;
    cout << "sz: " << sz << endl;  // 6
  }

  // Reference Returns Are Lvalues
  {
    // Calls to functions that return references are lvalues;
    // other return types yield rvalues.
    // A call to a function that returns a reference can be used
    // in the same ways as any other lvalue.

    string s("a value");
    cout << s << endl;    // prints a value
    get_val(s, 0) = 'A';  // changes s[0] to A
    cout << s << endl;    // prints A value
  }

  // List Initializing the Return Value
  {
    // Under the new standard, functions can return a braced list of values.
    // As in any other return,
    // the list is used to initialize the temporary
    // that represents the function’s return.
    auto res = process();
  }

  // Return from main
  {
      /*
      if (some_failure)
        return EXIT_FAILURE;
      else
        return EXIT_SUCCESS;
      */
  }

  // Recursion
  {
    // get factoral
    cout << factorial(5) << endl;
  }

  /********************************************************
  6.3.3. TODO: Returning a Pointer to an Array
  (Exercises 6.36 ~ 6.38)
  ********************************************************/

  // type alias
  {
      /*
      typedef int arrT[10];  // arrT is a synonym for the type array of ten ints
      using arrT = int[10];  // equivalent declaration of arrT
      arrT *func(int i);  // func returns a ptr to an arr of five ints
      */
  }

  // Declaring a Function That Returns a Pointer to an Array
  {
    // *   : "point to"
    // []  : "array of"
    // &   : "refer to"

    int arr[10];          // arr is an array of ten ints
    int *pl[10];          // p1 is an array of ten pointers
    int(*p2)[10] = &arr;  // p2 points to an array of ten ints

    // syntax:
    // Type (*fx (param_list)) [dimension]

    /*
    auto func(int i) -> int(*)[10]
    int (*func (int i)) [10]
          ------------       (1)
        ---------------      (2)
    ------------------------ (3)

    (1):  we can call func with an int arg
    (2):  we can dereference the result of that call
    (3):  dereferencing the result of a call to func
          yields an array of size ten
    */
  }

  // Using a Trailing Return Type
  {
      /*
      // fcn takes an int argument and returns a pointer to an array of ten ints
      auto func(int i) -> int(*)[10]
      */
  }

  // Using decltype (TODO: not easy)
  {
    int odd[] = {1, 3, 5, 7, 9};
    int even[] = {0, 2, 4, 6, 8};

    for (int i = 0; i < 5; i++) {
      cout << (*arrPtr(10))[i] << endl;
    }
  }

  /*
   - Because we cannot copy an array, a function cannot return an array.
   - However, a function can return a pointer or a reference to an array
  */

  return 0;
}

// return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string &word, const string &ending) {
  // TODO: returning local string???
  //       In C lang, it is impossible to return local character array!
  return (ctr > 1) ? word + ending : word;
}

// return a reference to the shorter of two strings
const string &shorterString(const string &s1, const string &s2) {
  return s1.size() <= s2.size() ? s1 : s2;
}

char &get_val(string &str, string::size_type ix) {
  return str[ix];  // get_val assumes the given index is valid
}

vector<string> process() {
  auto expected = string{};
  auto actual = string{"abc"};

  if (expected.empty())
    return {};
  else if (expected == actual)
    return {"functionX", "okay"};
  else
    return {"functionX", expected, actual};
}

// recursive
int factorial(int val) {
  if (val > 1) return factorial(val - 1) * val;
  return 1;
}

/*
Section 6.4 Overloaded Functions
Section 6.5 Features for Specialized Uses
Section 6.6 Function Matching
Section 6.7 Pointers to Functions
*/