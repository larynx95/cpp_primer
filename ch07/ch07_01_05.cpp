/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 7. Classes

Section 7.1 Defining Abstract Data Types
******************************************************************************/

/*
7.1.1. Designing the Sales_data Class (Exercises 1.25)
7.1.2. Defining the Revised Sales_data Class (Exercises 7.2~5)
  - defining member function
  - introduction to `this`
  - Introducing const Member Functions
  - Class Scope and Member Functions
  - Defining a Member Function outside the Class
  - Defining a Function to Return “This” Object
7.1.3. Defining Nonmember Class-Related Functions (Exericses 7.6~10)
  - Defining the read and print Functions
  - Defining the add Function
7.1.4. Constructors (Exercises 7.11~7.15)
  - The Synthesized Default Constructor
  - Some Classes Cannot Rely on the Synthesized Default Constructor
  - Defining the Sales_data Constructors
  - What "= default" Means
  - Constructor Initializer List
  - Defining a Constructor outside the Class Body
7.1.5. Copy, Assignment, and Destruction
- Some Classes Cannot Rely on the Synthesized Versions
*/

#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
  // constructors added
  Sales_data() = default;

  // nonmember Sales_data interface functions
  Sales_data add(const Sales_data &, const Sales_data &);
  std::ostream &print(std::ostream &, const Sales_data &);
  std::istream &read(std::istream &, Sales_data &);
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}
  Sales_data(std::istream &);

  // other members as before
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &);
  double avg_price() const;
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

// pseudo-code illustration of how the implicit this pointer is used
// this code is illegal: we may not explicitly define the this pointer ourselves
// note that this is a pointer to const because isbn is a const member
/*
std::string Sales_data::isbn(const Sales_data *const this) {
  return this->isbn;
}
*/

std::string Sales_data::isbn() const {
  // introduction to `this`
  return this->bookNo;
}

// Defining a Member Function outside the Class
double Sales_data::avg_price() const {
  if (units_sold)
    return revenue / units_sold;
  else
    return 0;
}

// Defining a Function to Return “This” Object
Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;  // add the members of rhs into
  revenue += rhs.revenue;        // the members of ''this'' object
  return *this;  // return the object on which the function was called
}

// Defining the read and print Functions
// input transactions contain ISBN, number of copies sold, and sales price
istream &read(istream &is, Sales_data &item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

ostream &print(ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
     << item.avg_price();
  return os;
}

// Defining the add Function
Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;  // copy data members from lhs into sum
  sum.combine(rhs);      // add data members from rhs into sum
  return sum;
}

// TODO: Defining a Constructor outside the Class Body
Sales_data::Sales_data(std::istream &is) {
  read(is, *this);  // read will read a transaction from is into this object
}

/*
Section 7.2 Access Control and Encapsulation
Section 7.3 Additional Class Features
Section 7.4 Class Scope
Section 7.5 Constructors Revisited
Section 7.6 static Class Members
*/