/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.3: Revise your transaction-processing program from § 7.1.1 (p.
256) to use these members.

*/

#include <iostream>
#include <string>
using namespace std;

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
 * main function
 **********************************************************/

int main() {
  Sales_data total;
  if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
    Sales_data transaction;
    while (cin >> transaction.bookNo >> transaction.units_sold >>
           transaction.revenue) {
      if (total.isbn() == transaction.isbn()) {
        total.combine(transaction);
      } else {
        cout << "ISBN: " << total.bookNo << endl
             << "Units sold: " << total.units_sold << endl
             << "Total revenue: " << total.revenue << endl
             << endl;
        total = transaction;
      }
    }
    cout << "ISBN: " << total.bookNo << endl
         << "Units sold: " << total.units_sold << endl
         << "Total revenue: " << total.revenue << endl;
  } else {
    std::cerr << "No data?!" << endl;

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

void print_data(const Sales_data& data) {
  std::cout << "\tISBN: " << data.bookNo << std::endl
            << "\tUnits sold: " << data.units_sold << std::endl
            << "\tTotal revenue: " << data.revenue << std::endl;
}