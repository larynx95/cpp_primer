/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 02. Variables and Basic Types

Section 2.1 Primitive Built-in Types
Section 2.2 Variables
******************************************************************************/

#include <iostream>

#include "Sales_item.h"

double applyDiscount(double price, double discount);

int main() {
  /********************************************************
   2.2.1 variable definition
   (Exercises 2.9 ~ 2.10)
   ********************************************************/

  int sum = 0, value,  // sum, value, and units_sold have type int
      units_sold = 0;  // sum and units_sold have initial value 0
  Sales_item item;     // item has type Sales_item (see § 1.5.1 (p. 20))
  // string is a library type, representing a variable-length sequence of
  // characters
  std::string book("0-201-78345-X");
  std::string book2{"adfsdafas"};  // list initializer
  std::cout << book << " " << book2 << std::endl;
  // book initialized from string literal

  /********************************************************
   * initializers
   ********************************************************/

  // ok: price is defined and initialized before it is used to initialize
  // discount
  double price = 109.99, discount{price * 0.16};
  // ok: call applyDiscount and use the return value to initialize salePrice
  double salePrice = applyDiscount(price, discount);
  std::cout << "discounted price is " << salePrice << std::endl;

  /********************************************************
  2.2.2 Variable declaration, definition, initialization
  (Exercises 2.11)
  ********************************************************/

  // Variable must be defined exactly ONCE
  // but can be declared many times.

  extern int i;  // declared but not defined
  extern int i;  // declared but not defined
  extern int i;  // declared but not defined

  // A variable declaration specifies the type and name of a variable.
  // A variable definition is a declaration.
  // In addition to specifying the name and type,
  // a definition also allocates storage
  // and may provide the variable with an initial value.

  // To obtain a declaration that is not also a definition,
  // we add the 'extern' keyword
  // and may not provide an explicit initializer.

  // Any declaration that includes an explicit initializer is a definition.
  // We can provide initializer on a variable defined as 'extern',
  // but doing so override the 'extern'.
  // An 'extern' that has an initializer is a definition.

  extern int i;  // declares but does not define i, defined in other file
  int j;         // declares and defines j
  // extern double pi = 3.1416;  // definition

  // The distinction between a declaration and a definition
  // may seem obscure at this point but is actually important.
  // To use a variable in more than one file requires
  // declarations that are separate from the variable’s definition.
  // To use the same variable in multiple files,
  // we must define that variable in one - and only one - file.
  // Other files that use that variable must declare
  // - but not define - that variable.

  // Why does initializing an extern variable inside a function give an error?
  // https://stackoverflow.com/questions/17090354/why-does-initializing-an-extern-variable-inside-a-function-give-an-error

  /********************************************************
   * 2.2.3. Identifiers
   * 2.2.4. Scope
   ********************************************************/

  return 0;
}

double applyDiscount(double price, double discount) { return price - discount; }

/*
Section 2.3 Compound Types
Section 2.4 const Qualifier
Section 2.5 Dealing with Types
Section 2.6 Defining Our Own Data Structures
*/
