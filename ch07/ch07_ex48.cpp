/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.48: Assuming the Sales_data constructors are not explicit,
what operations happen during the following definitions

string null_isbn("9-999-99999-9");
Sales_data item1(null_isbn);
Sales_data item2("9-999-99999-9");

What happens if the Sales_data constructors are explicit?

Answer:
https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.48.md

If the constructors are not explicit.

string null_isbn("9-999-99999-9");  // call string ctor
Sales_data item1(null_isbn);  // call Sales_data ctor
Sales_data item2("9-999-99999-9");
// first cover "9-999-99999-9" to string, then call Sales_data ctor

If the constructors are explicit, the same operations happen.

*/
