/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 3. Strings, Vectors, and Arrays

Section 3.1 Namespace using Declarations
Section 3.2 Library string Type
Section 3.3 Library vector Type
Section 3.4 Introducing Iterators
Section 3.5 Arrays
Section 3.6 Multidimensional Arrays
******************************************************************************/

#include <iostream>
using namespace std;

// utility function for printing 2D array
template <typename T>
void print2dArr(T *arr, int nrow, int ncol) {
  for (int i = 0; i < nrow; i++) {
    for (int j = 0; j < ncol; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  // multidiemensional array
  {
    int ia[3][4];
    // array of size 3; each element is an array of ints of size 4
    // array of size 10; each element is a 20-element array
    // whose elements are arrays of 30 ints
    int arr[10][20][30] = {0};  // initialize all elements to 0
  }

  // Initializing the Elements of a Multidimensional Array
  {
    // a. with nested braces
    int ia1[3][4] = {
        // three elements; each element is an array of size 4
        {0, 1, 2, 3},   // initializers for the row indexed by 0
        {4, 5, 6, 7},   // initializers for the row indexed by 1
        {8, 9, 10, 11}  // initializers for the row indexed by 2
    };

    // b. without nested braces
    int ia2[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    // c. initialize only element 0 in each row
    int ia3[3][4] = {{0}, {4}, {8}};
    print2dArr(ia3, 3, 4);

    // d. explicitly initialize row 0
    int ia4[3][4] = {0, 3, 6, 9};
    // initializes the elements of the first row.
    // The remaining elements are initialized to 0.
    print2dArr(ia4, 3, 4);
  }

  // subscripting a multidimensional array
  {
    // TODO: "There are no "multi-dimensional arrays" in C++."
    //        What's the meaning if this?
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int arr[10][20][30] = {0};

    // assigns the 1st elem of arr to the last elem in the last row of ia
    ia[2][3] = arr[0][0][0];
    int(&row)[4] = ia[1];  // binds row to the second four-element array in ia
    cout << "ia[2][3]: " << ia[2][3] << endl;
    for (int i = 0; i < sizeof(row) / sizeof(int); i++) {
      cout << row[i] << endl;
    }
  }

  // pari of for-loops to process the elems in multidimensional array
  {
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];  // 12 uninitialized elements
    for (size_t i = 0; i != rowCnt; ++i) {
      for (size_t j = 0; j != colCnt; ++j) {
        ia[i][j] = i * colCnt + j;
      }
    }
  }

  // using a range for with multidimensional arrays
  {
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    size_t cnt = 0;
    for (auto &row : ia) {     // for every element in the outer array
      for (auto &col : row) {  // for every element in the inner array
        col = cnt;             // give this element the next value
        ++cnt;                 // increment cnt
      }
    }
    cout << "cnt: " << cnt << endl;
  }

  // using reference for looping
  {
    /* TODO: Why should we us reference in looping?
      a. want to change element value
      b. avoid the normal array to pointer conversion

                ___  <--- this "row" is pointer variable!
      for (auto row : ia)     // row is a nesting array (pointer)
        for (auto col : row)  // pointer can't be used like this

           { {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9,10,11} }
             ------------  ------------  ------------
      rows:   ia[0]         ia[1]         ia[2]   <-- array name (~ pointer)
    */
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    for (const auto &row : ia) {  // for every element in the outer array
      for (auto col : row) {      // for every element in the inner array
        cout << col << " ";
      }
    }
    cout << endl;

    /* TODO: Error. Fix this.(Hint. Use pointer arithmetic)
    for (const auto row : ia) {
      for (auto col : row) {
        cout << col << " ";
      }
    }
    cout << endl;
    */
  }

  // Pointers and Multidimensional Arrays
  {
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    //              ----------  ----------  ------------
    //              {0,1,2,3}   {4,5,6,7}   {8,9,10,11}
    // array of size 3
    // each element is an array of ints of size 4

    int(*p)[4] = ia;  // p points to an array of four ints
    p = &ia[2];       // p now points to the last element in ia

    // print the value of each element in ia,
    // with each inner array on its own line
    // p points to an array of four ints
    for (auto p = ia; p != ia + 3; ++p) {
      // q points to the first element of an array of four ints; that is, q
      // points to an int
      for (auto q = *p; q != *p + 4; ++q) cout << *q << ' ';
      cout << endl;
    }
  }

  // using begin(), and end()
  {
    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    for (auto p = begin(ia); p != end(ia); ++p) {
      for (auto q = begin(*p); q != end(*p); ++q) {
        cout << *q << ' ';
      }
      cout << endl;
    }
  }

  // Type Aliases Simplify Pointers to Multidimensional Arrays
  {
    // What is the difference between 'typedef' and 'using' in C++11?
    // https://stackoverflow.com/questions/10747810/what-is-the-difference-between-typedef-and-using-in-c11

    int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    using int_array = int[4];
    // new style type alias declaration; see § 2.5.1 (p. 68)
    typedef int int_array[4];
    // equivalent typedef declaration; § 2.5.1 (p. 67)
    // print the value of each element in ia, with each inner array on its own
    // line
    for (int_array *p = ia; p != ia + 3; ++p) {
      for (int *q = *p; q != *p + 4; ++q) cout << *q << ' ';
      cout << endl;
    }
  }

  return 0;
}