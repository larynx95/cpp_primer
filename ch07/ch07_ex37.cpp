/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.37: Using the version of Sales_data from this section,
determine which constructor is used to initialize each of the following
variables and list the values of the data members in each object:

    Sales_data first_item(cin);

    int main() {
      Sales_data next;
      Sales_data last("9-999-99999-9");
    }

Answer:

    Sales_data first_item(cin);          // Sales_data(std::istream &is);

    int main() {
      Sales_data next;                   // Sales_data(std::string s = "");
      Sales_data last("9-999-99999-9");  // Sales_data(std::string s = "");
    }

*/

#include <iostream>

int main() {
  //
  return 0;
}