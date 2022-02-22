/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.1:
Write a version of the transaction-processing program from § 1.6 (p. 24)
using the Sales_data class you defined for the exercises in § 2.6.1 (p. 72).

- This program works for only ONE book.

*/

#include <iostream>
#include <string>
using namespace std;

struct Sales_data {
  std::string bookNo;
  unsigned units_sold = 0;
  double price = 0.0;
  double revenue = 0.0;
};

int main() {
  Sales_data total;
  if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
    Sales_data transaction;
    while (cin >> transaction.bookNo >> transaction.units_sold >>
           transaction.revenue) {
      if (total.bookNo == transaction.bookNo) {
        total.units_sold += transaction.units_sold;
        total.revenue += transaction.revenue;
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