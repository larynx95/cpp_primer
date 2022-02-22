/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 7. Classes

Section 7.1 Defining Abstract Data Types
******************************************************************************/

/*
7.1.1. Designing the Sales_data Class (Exercises 1.25)

    ```cpp
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
      Sales_data bk;
      cout << "selected book number, units sold, revenue: ";
      if (cin >> bk.bookNo >> bk.units_sold >> bk.revenue) {
        Sales_data sel;
        while (cin >> sel.bookNo >> sel.units_sold >>sel.revenue) {
          if (bk.bookNo == sel.bookNo) {
            bk.units_sold += sel.units_sold;
            bk.revenue += sel.revenue;
          } else {
            cout << "ISBN:" << bk.bookNo << endl
                << "Units sold: " << bk.units_sold << endl
                << "Total revenue: " << bk.revenue << endl
                << endl;
            bk = sel;
          }
        }
        cout << "ISBN: " << bk.bookNo << endl
            << "Units sold: " << bk.units_sold << endl
            << "Total revenue: " << bk.revenue << endl;
      } else {
        std::cerr << "No data?!" << endl;
        return -1;
      }
      return 0;
    }
    ```

7.1.2. Defining the Revised Sales_data Class
- defining member function
- introduction to `this`

    ```cpp
    struct Sales_data {
      // new members: operations on Sales_data objects
      std::string isbn() const { return bookNo; }  // TODO: member functions
      Sales_data& combine(const Sales_data&);
      double avg_price() const;
      // data members are unchanged from § 2.6.1 (p. 72)
      std::string bookNo;
      unsigned units_sold = 0;
      double revenue = 0.0;
    };

    // nonmember Sales_data interface functions
    Sales_data add(const Sales_data&, const Sales_data&);
    std::ostream &print(std::ostream&, const Sales_data&);
    std::istream &read(std::istream&, Sales_data&);
    ```

- `std::string isbn() const { return this->bookNo; }`

    ```cpp
    // Don't try this! This code only for explanation.
    // pseudo-code illustration of how the implicit this pointer is used
    // this code is illegal:
    // we may not explicitly define the this pointer ourselves
    // note that this is a pointer to const because isbn is a const member
    std::string Sales_data::isbn(const Sales_data *const this)
      { return this->isbn; }
    ```
- introducing const member function (TODO: `const` again...)
  Objects that are const, and references or pointers to const objects,
  may call only const member functions.

- defining a member function outside the class

- defining a function to return "this" object

    ```cpp
    Sales_data& Sales_data::combine(const Sales_data &rhs) {
      units_sold += rhs.units_sold; // add the members of rhs into
      revenue += rhs.revenue;       // the members of ''this'' object
      return *this;       // return the object on which the function was called
    }

    // TODO: Can the const param's member be modified?
    ```
7.1.3. Defining Nonmember Class-Related Functions
- Defining the read and print Functions

    ```cpp
    // input transactions contain ISBN, number of copies sold, and sales price
    istream &read(istream &is, Sales_data &item) {
      double price = 0;
      is >> item.bookNo >> item.units_sold >> price;
      item.revenue = price * item.units_sold;
      return is;
    }

    ostream &print(ostream &os, const Sales_data &item) {
      os << item.isbn() << " " << item.units_sold << " "
      << item.revenue << " " << item.avg_price();
      return os;
    }
    ```

- Defining the add Function

    ```cpp
    Sales_data add(const Sales_data &lhs, const Sales_data &rhs){
      Sales_data sum = lhs; // copy data members from lhs into sum
      sum.combine(rhs); // add data members from rhs into sum
      return sum;
    }
    ```

7.1.4. Constructors
- The Synthesized Default Constructor (compiler-generated constructor)
  if there's no explicit constructor

    ```cpp
    Sales_data total; // variable to hold the running sum
    Sales_data trans; // variable to hold data for the next transaction
    ```

- Some Classes Cannot Rely on the Synthesized Default Constructor

- Defining the Sales_data Constructors
  - An istream& from which to read a transaction.
  - A const string& representing an ISBN ,
    an unsigned representing the count of how many books were sold,
    and a double representing the price at which the books sold.
  - A const string& representing an ISBN .
    This constructor will use default values for the other members.
  - An empty parameter list (i.e., the default constructor)
    which as we’ve just seen we must define
    because we have defined other constructors.

    ```cpp
    struct Sales_data {
      // TODO: constructors added
      // https://en.cppreference.com/w/cpp/language/default_constructor
      Sales_data() = default;  // TODO: Is this required?
      Sales_data(const std::string &s): bookNo(s) { }
      Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) { }
      Sales_data(std::istream &);  // TODO: What is this?

      // other members functions as before
      std::string isbn() const { return bookNo; }
      Sales_data& combine(const Sales_data&);
      double avg_price() const;

      // fields
      std::string bookNo;
      unsigned units_sold = 0;
      double revenue = 0.0;
    };
    ```
- Constructor Initializer List

    ```cpp
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
      bookNo(s), units_sold(n), revenue(p*n) { }
    ```

- Defining a Constructor outside the Class Body

    ```cpp
    Sales_data::Sales_data(std::istream &is) {
      read(is, *this); // read will read a transaction from is into this object
    }
    ```

7.1.5. Copy, Assignment, and Destruction (TODO: chapter 13)

*/

#include <iostream>

int main() {
  //
  return 0;
}

/*
Section 7.2 Access Control and Encapsulation
Section 7.3 Additional Class Features
Section 7.4 Class Scope
Section 7.5 Constructors Revisited
Section 7.6 static Class Members
*/