/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.2: Add the combine and isbn members to the Sales_data
class you wrote for the exercises in § 2.6.2 (p. 76). Exercise 2.41

https://github.com/adobrich/CppPrimer/blob/master/Chapter_07/exercise_02.cpp
*/

#include <iostream>
#include <string>

/**********************************************************
 * structure declaration, prototypes
 **********************************************************/

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  std::string isbn() const;
  Sales_data& combine(const Sales_data& transaction);
};

void print_data(const Sales_data& data);

/**********************************************************
 * maion function
 **********************************************************/

int main() {
  Sales_data total;
  Sales_data sale;

  total.bookNo = "0-006-47988";
  total.units_sold = 10;
  total.revenue = 50.0;

  sale.bookNo = "0-006-47988";
  sale.units_sold = 5;
  sale.revenue = 50.0;

  std::cout << "First transaction:" << std::endl;
  print_data(total);
  std::cout << "Second transaction:" << std::endl;
  print_data(sale);
  std::cout << "Transactions combined:" << std::endl;
  print_data(total.combine(sale));

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

void print_data(const Sales_data& data) {
  std::cout << "\tISBN: " << data.bookNo << std::endl
            << "\tUnits sold: " << data.units_sold << std::endl
            << "\tTotal revenue: " << data.revenue << std::endl;
}