/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 3. Strings, Vectors, and Arrays

Section 3.1 Namespace using Declarations
Section 3.2 Library string Type
Section 3.3 Library vector Type
Section 3.4 Introducing Iterators
Section 3.5 Arrays
******************************************************************************/

#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

constexpr int get_size() { return 100; }

int main() {
  /********************************************************
  3.5.1. Defining and Initializing Built-in Arrays
  (Exercises 3.27 ~ 3.29)
  ********************************************************/

  // defining & initializing built-in arrays
  {
    unsigned cnt = 42;           // not a constant expression
    constexpr unsigned sz = 42;  // constant expression
    // constexpr see § 2.4.4 (p. 66)
    int arr[10];    // array of ten ints
    int *parr[sz];  // array of 42 pointers to int

    // string bad[cnt];  // error: cnt is not a constant expression
    string strs[get_size()];  // ok if get_size is constexpr, error otherwise
  }

  // explicit initialization
  {
    const unsigned sz = 3;          // constexpr
    int ia1[sz] = {0, 1, 2};        // array of three ints with values 0, 1, 2
    int ia2[] = {0, 1, 2};          // an array of dimension 3
    int ia3[5] = {0, 1, 2};         // equivalent to a3[] = {0, 1, 2, 0, 0}
    string sa4[3] = {"hi", "bye"};  // same as a4[] = {"hi", "bye", ""}
    // int ia5[2] = {0, 1, 2};      // error: too many initializers
  }

  // Character Arrays Are Special
  {
    char a1[] = {'C', '+', '+'};        // list initialization, no null
    char a2[] = {'C', '+', '+', '\0'};  // list initialization, explicit null
    char a3[] = "C++";                  // null terminator added automatically
    // const char a4[6] = "Daniel";     // error: no space for the null!
  }

  // No Copy or Assignment
  {
    int a[] = {0, 1, 2};  // array of three ints
    // int a2[] = a;      // error: cannot initialize one array with another
    // a2 = a;            // error: cannot assign one array another
  }

  // Understanding Complicated Array Declarations
  {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptrs[10];  // ptrs is an array of ten pointers to int
    // int &refs[10] = /* ? */;  // error: no arrays of references
    int(*Parray)[10] = &arr;  // a pointer points to an array of ten ints
    int(&arrRef)[10] = arr;   // refers to an array of ten ints
    int *(&arry)[10] = ptrs;  // a reference to an array of ten pointers

    /*
    spiral rule:         decipher:
             ┌--2┐       1: arry is a reference
    int *(&arry)[10]     2: to array of ten
    4     └-1┘   |       3: pointers
        └-------3┘       4: to int type
    */
  }

  /********************************************************
  3.5.2. Accessing the Elements of an Array
  (Exercises 3.30 ~ 3.33)
  ********************************************************/

  // grading example as in vector section
  {
    // count the number of grades by clusters of three:
    // if index is bw 0--2, add grade to the 1st cluster- scores[0]
    // if index is bw 3--5, add grade to the 2nd cluster- scores[1]
    // if index is bw 6--8, add grade to the 3rd cluster- scores[2]
    unsigned scores[3] = {};  // 11 buckets, all value initialized to 0
    unsigned grade;
    while (cin >> grade && grade != 0) {
      if (grade <= 100)
        ++scores[grade / 3];  // increment the counter for the current cluster
    }
  }

  /********************************************************
  3.5.3. Pointers and Arrays
  (Exercises 3.34 ~ 3.36)
  ********************************************************/

  // pointer and array name
  {
    string nums[] = {"one", "two", "three"};  // array of strings
    string *p = &nums[0];  // p points to the first element in nums
    // string *sptr2 = nums; // equivalent to p2 = &nums[0]

    // Arrays have a special property.
    // In most places when we use an array,
    // the compiler automatically substitutes a pointer
    // to the first element

    // TODO: But ... which is the best and correct way?
    // TODO: Is an array name a pointer?
    // https://stackoverflow.com/questions/1641957/is-an-array-name-a-pointer
  }

  // operations on arrays == operations on pointers
  {
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // ia is an array of ten ints
    auto is2(ia);  // ia2 is an int* that points to the first element in ia
    // ia = 42;   // error: ia is a pointer, can't assign an int to a pointer

    decltype(ia) ia3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // ia3 is an array of ten ints
    // ia3 = p;     // error: can't assign an int* to an array
    // ia3[4] = i;  // ok: assigns the value of i to an element in ia3
  }

  // Pointers Are Iterators
  {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *sptr2 = arr;  // p points to the first element in arr
    ++sptr2;           // p points to arr[1]
  }

  // The Library begin and end Functions
  {
    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // ia is an array of ten ints
    int *beg = begin(ia);  // pointer to the first element in ia
    int *last = end(ia);   // pointer one past the last element in ia

    // Array is not class.
    // These "begin" and "end" library functions are not member functions.
  }

  // Pointer Arithmetic
  {
    constexpr size_t sz3 = 5;
    int arr[sz3] = {1, 2, 3, 4, 5};
    int *ip = arr;      // equivalent to int *ip = &arr[0]
    int *ip2 = ip + 4;  // ip2 points to arr[4], the last element in arr

    // ok: arr is converted to a pointer to its first element;
    // p points one past the end of arr
    // int *p = arr + sz;  // use caution -- do not dereference!
    // int *p2 = arr + 10;
    // error: arr has only 5 elements; p2 has undefined value

    // get the size of array
    auto n = end(arr) - begin(arr);  // n is 5, the number of elements in arr
  }

  // Interaction between Dereference and Pointer Arithmetic
  {
    int ia[] = {0, 2, 4, 6, 8};  // array with 5 elements of type int
    int last = *(ia + 4);  // ok: initializes last to 8, the value of ia[4]
  }

  // subscripts and pointers
  {
    int ia[] = {0, 2, 4, 6, 8};  // array with 5 elements of type int
    int i = ia[2];  // ia[2] fetches the element to which (ia + 2) points
    int *p = ia;    // p points ot the first element in ia
    i = *(p + 2);   // equivalent to i = ia[2]

    int *ptr = &ia[2];  // p points to the element indexed by 2
    int j = ptr[1];     // p[1] is equivalent to *(p + 1)
    int k = ptr[-2];    // p[-2] is the same element as ia[0]
  }

  /********************************************************
  3.5.4. C-Style Character Strings
  (Exercises 3.37 ~ 3.40)
  ********************************************************/

  // C-style character string functions
  {
      /*
      strlen(p)      : returns the length of p, not counting the null
      strcmp(p1, p2) : compares p1 and p2 for equality
      strcat(p1, p2) : append p2 to p1, return p1
      strcpy(p1, p2) : copies p2 into p1, returns p1
      */
  }

  // not null terminated string
  {
      // char ca[] = {'C', '+', '+'};  // not null terminated
      // cout << strlen(ca) << endl;   // disaster: ca isn't null terminated
  }

  // comparing strings: string vs. const char
  {
    // comparing two strings - size, each character
    string s1 = "A string example";
    string s2 = "A different string";
    cout << (s1 < s2) << endl;  // 0

    // comparing two arrays of const characters
    // TODO: BE CAREFUL!
    // These compares the pointer values (address),
    // NOT the strings themselves!
    const char ca1[] = "A string example";
    const char ca2[] = "A different string";
    cout << (ca1 < ca2) << endl;  // 0, TODO: undefined!!
    cout << (ca2 < ca1) << endl;  // 1, TODO: undefined!!
    cout << "ca1: " << ca1 << endl;
    cout << "ca2: " << ca2 << endl;

    // To compare the strings, rather than the pointer values,
    // we can call strcmp function.
  }

  // c_str() : "string type (C++)" to "const char* (C style)" type
  {
    // http://www.cplusplus.com/reference/string/string/c_str/

    string sample("Hello World");  // s holds Hello World
    // char *str = sample;   // error: can't initialize a char* from a string
    const char *str = sample.c_str();  // ok

    cout << typeid(sample).name() << endl;  // Ss (string)
    cout << typeid(str).name() << endl;     // PKc (const char*)
  }

  // caller is responsible for size of a destination string
  {
    // concatenating two strings
    string s1 = "Hello";
    string s2 = "World";
    string largeStr = s1 + " " + s2;

    // concatenating two const char arrays
    // disastrous if we miscalculated the size of largeStr2
    char largeStr2[12];
    const char ca1[] = "Hello";
    const char ca2[] = "World";
    strcpy(largeStr2, ca1);
    strcat(largeStr2, " ");
    strcat(largeStr2, ca2);
    cout << "largeStr2: " << largeStr2 << endl;
  }

  /********************************************************
  3.5.5. Interfacing to Older Code
  (Exercises 3.41 ~ 3.42)
  ********************************************************/

  // mixing library strings and C-Style strings
  {
    // using null-terminated character array
    // a. We can use a null-terminated character array
    //    to initialize or assign a string.
    // b. We can use a null-terminated character array
    //    as one operand (but not both operands)
    //    to the string addition operator
    //    or as the right-hand operand
    //    in the string compound assignment (+=) operator.

    // a. initializing string with character array
    string s("Hello World");
    // char *str = s;   // error: can't initialize a char* from a string
    const char *str = s.c_str();  // ok
    cout << str << endl;

    // b. initializing character array with string
    const char *cs = "Hello world";
    string str1 = cs;
    cout << str1 << endl;
  }

  // using an array to initialize a vector
  {
    int int_arr[] = {0, 1, 2, 3, 4, 5};
    vector<int> ivec(begin(int_arr), end(int_arr));
    for (auto it = ivec.begin(); it != ivec.end(); ++it) {
      cout << *it << " ";
    }
    cout << endl;

    // copies three elements: int_arr[1], int_arr[2], int_arr[3]
    vector<int> subVec(int_arr + 1, int_arr + 4);
    for (auto it = subVec.begin(); it != subVec.end(); ++it) {
      cout << *it << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
Section 3.6 Multidimensional Arrays
*/