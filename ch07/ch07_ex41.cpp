/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.41: Rewrite your own version of the Sales_data class to use
delegating constructors. Add a statement to the body of each of the
constructors that prints a message whenever it is executed. Write
declarations to construct a Sales_data object in every way possible. Study
the output until you are certain you understand the order of execution among
delegating constructors.

https://github.com/chihyang/CPP_Primer/blob/master/chap07/Exer07_41_Sales_data.h
*/

#include <iostream>
#include <string>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

/**********************************************************
 * class definition, prototypes
 **********************************************************/

// substitute class for struct
class Sales_data {
  // friend
  friend istream& read(istream&, Sales_data&);
  friend ostream& print(ostream& os, const Sales_data& item);
  friend Sales_data add(const Sales_data& item1, const Sales_data& item2);

 public:
  // constructor
  Sales_data() : Sales_data("", 0, 0) { cout << "Sales_data()" << endl; }
  Sales_data(const string& s) : Sales_data(s, 0, 0) {
    cout << "Sales_data(const string &s)" << endl;
  }
  Sales_data(const string& s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {
    cout << "Sales_data(const string &s, unsigned n, double p)" << endl;
  }
  Sales_data(istream& is) : Sales_data() {
    cout << "Sales_data(istream &is)" << endl;
    read(is, *this);
  }
  // member
  Sales_data& combine(const Sales_data& rhs);
  string isbn() const { return bookNo; }

 private:
  string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
  double avg_price() const;
};

// declare friend functions outside class
istream& read(istream&, Sales_data&);
ostream& print(ostream& os, const Sales_data& item);
Sales_data add(const Sales_data& item1, const Sales_data& item2);

/**********************************************************
 * main function
 **********************************************************/

int main() {
  cout << "item1: " << endl;
  // first call Sales_data(const string&, unsigned, double), then Sales_data()
  Sales_data item1;
  cout << "item2: " << endl;
  // call Sales_data(const string&, unsigned, double)
  Sales_data item2("978-7-121-20038-0", 10, 128);
  cout << "item3: " << endl;
  // first call Sales_data(const string&, unsigned, double), then
  // Sales_data(const string &)
  Sales_data item3("978-7-100-09211-1");
  cout << "item4: " << endl;
  // first call Sales_data(const string&, unsigned, double), then Sales_data(),
  // at last Sales_data(istream &is)
  Sales_data item4(cin);
  return 0;
}

/**********************************************************
 * function definitions
 **********************************************************/

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
istream& read(istream& is, Sales_data& item) {
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = item.units_sold * price;
  return is;
}

// Why does the book use an ostream reference as return value rather than void?
// 'Cause only in this way can user have a better manipulation of the format.
ostream& print(ostream& os, const Sales_data& item) {
  os << item.bookNo << " " << item.units_sold << " " << item.revenue << " "
     << item.avg_price();
  return os;
}

Sales_data add(const Sales_data& item1, const Sales_data& item2) {
  Sales_data sum = item1;
  sum.combine(item2);
  return sum;
}