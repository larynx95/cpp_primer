/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.12: Write a function named compareIsbn that compares the
isbn() members of two Sales_data objects. Use that function to sort a
vector that holds Sales_data objects.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "Sales_data.h"

class Sales_data {
  // friend dcl for non-members
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);
  friend Sales_data add(Sales_data &, Sales_data &);

 public:
  // constructors
  Sales_data() = default;
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}
  explicit Sales_data(std::istream &is) { read(is, *this); }
  // members
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &);

 private:
  double avg_price() const;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

// non-member function's declarations
std::istream &read(std::istream &, Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
Sales_data add(Sales_data &, Sales_data &);

bool compareIsbn(const Sales_data &item1, const Sales_data &item2);

int main() {
  std::vector<Sales_data> books{{"9-999-99999-9"}, {"1-111-11111-1"},
                                {"4-444-44444-4"}, {"7-777-77777-7"},
                                {"3-333-33333-3"}, {"5-555-55555-5"}};
  sort(books.begin(), books.end(), compareIsbn);
  for (auto const &book : books) print(std::cout, book);
  std::cout << '\n';
  return 0;
}

// member function's definitions
inline Sales_data &Sales_data::combine(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

inline double Sales_data::avg_price() const {
  if (units_sold)
    return revenue / units_sold;
  else
    return 0;
}

std::istream &read(std::istream &is, Sales_data &item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item) {
  os << item.isbn() << " " << item.units_sold << " " << item.revenue << " "
     << item.avg_price();
  return os;
}

Sales_data add(Sales_data &lhs, Sales_data &rhs) {
  Sales_data sum = lhs;
  sum.combine(rhs);
  return sum;
}

bool compareIsbn(const Sales_data &item1, const Sales_data &item2) {
  return item1.isbn() < item2.isbn();
}