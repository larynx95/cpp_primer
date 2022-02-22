/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.7: Rewrite the transaction-processing program you wrote for the
exercises in § 7.1.2 (p. 260) to use these new functions.

https://github.com/adobrich/CppPrimer/blob/master/Chapter_07/exercise_07.cpp

*/

#include <iostream>
#include <istream>
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
  Sales_data add(const Sales_data& first_transaction,
                 const Sales_data& second_transaction);
};

std::istream& read(std::istream& input, Sales_data& transaction);
std::ostream& print(std::ostream& output, const Sales_data& transaction);

/**********************************************************
 * main function
 **********************************************************/

int main() {
  Sales_data total;
  if (read(cin, total)) {
    Sales_data transaction;
    while (read(cin, transaction)) {
      if (total.isbn() == transaction.isbn()) {
        total.combine(transaction);
      } else {
        print(cout, total);
        cout << endl;
        total = transaction;
      }
    }
    print(cout, total);
    cout << endl;
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