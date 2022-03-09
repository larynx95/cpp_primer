/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 13. Copy Control

Exercise 13.12:
How many destructor calls occur in the following code fragment?

bool fcn(const Sales_data *trans, Sales_data accum)
{
  Sales_data item1(*trans), item2(accum);
  return item1.isbn() != item2.isbn();
}

************************************************/

#include <iostream>
#include <vector>

int main() {
  //
  return 0;
}