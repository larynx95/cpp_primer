/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.11: Add constructors to your Sales_data class and write a
program to use each of the constructors.

https://github.com/adobrich/CppPrimer/blob/master/Chapter_07/exercise_11.cpp
*/

#include <iostream>
#include <istream>
#include <string>

/**********************************************************
 * structure declaration, prototypes
 **********************************************************/

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;

  /* constructors
  - same names as structure itself
  - overloading
  */
  Sales_data() = default;
  Sales_data(const std::string& book_isbn) : bookNo(book_isbn) {}
  Sales_data(const std::string& book_isbn, unsigned units, double price)
      : bookNo(book_isbn), units_sold(units), revenue(units * price) {}
  Sales_data(std::istream& input);

  std::string isbn() const;
  Sales_data& combine(const Sales_data& transaction);

};  // Sales_data class

Sales_data add(const Sales_data& first_transaction,
               const Sales_data& second_transaction);
std::istream& read(std::istream& input, Sales_data& transaction);
std::ostream& print(std::ostream& output, const Sales_data& transaction);

/**********************************************************
 * main function
 **********************************************************/

int main() {
  Sales_data d1;
  Sales_data d2("0-201-78345-X");
  Sales_data d3("0-201-78345-X", 5, 2.5);
  Sales_data d4(std::cin);

  print(std::cout, d1) << std::endl;
  print(std::cout, d2) << std::endl;
  print(std::cout, d3) << std::endl;
  print(std::cout, d4) << std::endl;

  return 0;
}

/**********************************************************
 * function definitions
 **********************************************************/

Sales_data::Sales_data(std::istream& input) { read(input, *this); }

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
