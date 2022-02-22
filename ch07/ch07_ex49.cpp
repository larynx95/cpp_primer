/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.49: For each of the three following declarations of combine,
explain what happens if we call i.combine(s), where i is a Sales_data
and s is a string:
(a) Sales_data &combine(Sales_data);
(b) Sales_data &combine(Sales_data&);
(c) Sales_data &combine(const Sales_data&) const;

https://github.com/chihyang/CPP_Primer/blob/master/chap07/Exer07_49_Sales_data.h
*/

#include <iostream>
#include <string>
using namespace std;

// substitute class for struct
class Sales_data {
  // friend
  friend std::istream& read(std::istream&, Sales_data&);
  friend std::ostream& print(std::ostream& os, const Sales_data& item);
  friend Sales_data add(const Sales_data& item1, const Sales_data& item2);

 public:
  // constructor
  Sales_data() : Sales_data("", 0, 0) {
    std::cout << "Sales_data()" << std::endl;
  }
  Sales_data(const std::string& s) : Sales_data(s, 0, 0) {
    std::cout << "Sales_data(const std::string &s)" << std::endl;
  }
  Sales_data(const std::string& s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {
    std::cout << "Sales_data(const std::string &s, unsigned n, double p)"
              << std::endl;
  }
  Sales_data(std::istream& is) : Sales_data() {
    std::cout << "Sales_data(std::istream &is)" << std::endl;
    read(is, *this);
  }
  // member
  // Sales_data& combine(Sales_data); // combine #(a)
  // Sales_data& combine(Sales_data&); // combine #(b)
  Sales_data& combine(const Sales_data& rhs);  // combine #(c)
  std::string isbn() const { return bookNo; }

 private:
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  double avg_price() const;
};
// declare friend functions outside class
std::istream& read(std::istream&, Sales_data&);
std::ostream& print(std::ostream& os, const Sales_data& item);
Sales_data add(const Sales_data& item1, const Sales_data& item2);
// member functions definition
Sales_data& Sales_data::combine(const Sales_data& rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}
// define avg_price as inline, required by exercise 7.26
inline double Sales_data::avg_price() const {
  if (units_sold != 0)
    return revenue / units_sold;
  else
    return revenue;
}
// friend functions definition
std::istream& read(std::istream& is, Sales_data& item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = item.units_sold * price;
  return is;
}
// Why does the book use an std::ostream reference as return value rather than
// void? 'Cause only in this way can user have a better manipulation of the
// format.
std::ostream& print(std::ostream& os, const Sales_data& item) {
  os << item.bookNo << " " << item.units_sold << " " << item.revenue << " "
     << item.avg_price();
  return os;
}
Sales_data add(const Sales_data& item1, const Sales_data& item2) {
  Sales_data sum = item1;
  sum.combine(item2);
  return sum;
}

int main() {
  Sales_data item("978-7-121-20038-0", 10, 128);
  string s = "978-7-121-20038-0";
  // for Sales_data(const string&)
  // combine #(a) and combine #(c) work, combine #(b) doesn't compile
  // for explicit Sales_data(const string&)
  // combine #(a) , combine #(b), combine #(c) won't compile
  item.combine(s);
  return 0;
}