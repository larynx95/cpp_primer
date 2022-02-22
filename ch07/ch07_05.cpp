/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 7. Classes

Section 7.1 Defining Abstract Data Types
Section 7.2 Access Control and Encapsulation
Section 7.3 Additional Class Features
Section 7.4 Class Scope
Section 7.5 Constructors Revisited
******************************************************************************/

/*
7.5.2. Delegating Constructors

  ```cpp
  class Sales_data {
  public:
    // nondelegating constructor initializes members
    // from corresponding arguments
    Sales_data(std::string s, unsigned cnt, double price):
        bookNo(s), units_sold(cnt), revenue(cnt*price) { }
    // remaining constructors all delegate to another constructor
    Sales_data(): Sales_data("", 0, 0) {}
    Sales_data(std::string s): Sales_data(s, 0,0) {}
    Sales_data(std::istream &is): Sales_data() { read(is, *this); }
    // other members as before
  };
  ```

7.5.3. The Role of the Default Constructor

7.5.6. Literal Classes

    ```cpp
    class Debug {
    public:
      constexpr Debug(bool b = true): hw(b), io(b), other(b) {}
      constexpr Debug(bool h, bool i, bool o):
          hw(h), io(i), other(o) {}
      constexpr bool any() { return hw || io || other; }
      void set_io(bool b) { io = b; }
      void set_hw(bool b) { hw = b; }
      void set_other(bool b) { hw = b; }
    private:
      bool hw; // hardware errors other than IO errors
      bool io; // IO errors
      bool other; // other errors
    };
    ```

*/

/*
Section 7.6 static Class Members
*/