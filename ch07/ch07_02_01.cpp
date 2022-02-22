/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 7. Classes

Section 7.1 Defining Abstract Data Types
Section 7.2 Access Control and Encapsulation
- Using the class or struct Keyword (Exercises 7.16~19)
******************************************************************************/

/*
7.2.1. Friends
- Declarations for Friends (Exercises 7.20~22)
*/

#include <iostream>
using namespace std;

class Sales_data {
  // friend declarations for nonmember Sales_data operations added
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);

  // other members and access specifiers as before
 public:
  Sales_data() = default;
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(std::istream &);
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &);
  double avg_price() const;

 private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

// declarations for nonmember parts of the Sales_data interface
Sales_data add(const Sales_data &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);

int main() {
  //
  return 0;
}

std::string Sales_data::isbn() const {
  // introduction to `this`
  return this->bookNo;
}

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

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;  // copy data members from lhs into sum
  sum.combine(rhs);      // add data members from rhs into sum
  return sum;
}

Sales_data::Sales_data(std::istream &is) {
  read(is, *this);  // read will read a transaction from is into this object
}

/*
Section 7.3 Additional Class Features
Section 7.4 Class Scope
Section 7.5 Constructors Revisited
Section 7.6 static Class Members
*/