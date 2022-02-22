/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 7. Classes

Section 7.1 Defining Abstract Data Types
******************************************************************************/

/*
7.1.1. Designing the Sales_data Class (Exercises 1.25)
*/

#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

int main() {
  Sales_data total;        // variable to hold the running sum
  if (read(cin, total)) {  // read the first transaction
    Sales_data trans;      // variable to hold data for the next transaction
    while (read(cin, trans)) {           // read the remaining transactions
      if (total.isbn() == trans.isbn())  // check the isbns
        total.combine(trans);            // update the running total
      else {
        print(cout, total) << endl;  // print the results
        total = trans;               // process the next book
      }
    }
    print(cout, total) << endl;   // print the last transaction
  } else {                        // there was no input
    cerr << "No data?!" << endl;  // notify the user
  }

  return 0;
}

/*
Section 7.2 Access Control and Encapsulation
Section 7.3 Additional Class Features
Section 7.4 Class Scope
Section 7.5 Constructors Revisited
Section 7.6 static Class Members
*/