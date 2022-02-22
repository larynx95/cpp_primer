/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.14: Write a version of the default constructor that explicitly
initializes the members to the values we have provided as in-class initializers.

*/

#include <iostream>
#include <istream>
#include <string>
using namespace std;

/**********************************************************
 * structure declaration, prototypes
 **********************************************************/

struct Sales_data;
Sales_data add(const Sales_data& first_transaction,
               const Sales_data& second_transaction);
std::istream& read(std::istream& input, Sales_data& transaction);
std::ostream& print(std::ostream& output, const Sales_data& transaction);

/**********************************************************
 * structure declaration, prototypes
 **********************************************************/

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  Sales_data() : bookNo(""), units_sold(0), revenue(0.0) {}  // default values
  Sales_data(const std::string& book_isbn) : bookNo(book_isbn) {}
  Sales_data(const std::string& book_isbn, unsigned units, double price)
      : bookNo(book_isbn), units_sold(units), revenue(units * price) {}
  Sales_data(std::istream& input) { read(input, *this); }

  std::string isbn() const;
  Sales_data& combine(const Sales_data& transaction);
};

/**********************************************************
 * main function
 **********************************************************/

int main() {
  Sales_data total(std::cin);
  // if (read(std::cin, total)) {
  if (std::cin) {
    Sales_data trans(std::cin);
    // while (read(std::cin, trans)) {
    while (std::cin) {
      if (total.isbn() == trans.isbn()) {
        total.combine(trans);
      } else {
        print(std::cout, total) << std::endl;
        total = trans;  // Use default copy constructor
      }
      read(std::cin, trans);  // Read new transaction
    }
    print(std::cout, total) << std::endl;
  } else {
    std::cerr << "No data!" << std::endl;
    return -1;
  }

  return 0;
}

/**********************************************************
 * function definitions
 **********************************************************/

std::string Sales_data::isbn() const { return this->bookNo; }

Sales_data& Sales_data::combine(const Sales_data& transaction) {
  if (this->isbn() == transaction.isbn()) {
    this->units_sold += transaction.units_sold;
    this->revenue += transaction.revenue;
  }
  return *this;
}

Sales_data add(const Sales_data& first_transaction,
               const Sales_data& second_transaction) {
  Sales_data sum = first_transaction;
  sum.combine(second_transaction);
  return sum;
}

std::istream& read(std::istream& input, Sales_data& transaction) {
  double price = 0.0;
  input >> transaction.bookNo >> transaction.units_sold >> price;
  transaction.revenue = transaction.units_sold * price;
  return input;
}

std::ostream& print(std::ostream& output, const Sales_data& transaction) {
  output << transaction.isbn() << " " << transaction.units_sold << " "
         << transaction.revenue;
  return output;
}