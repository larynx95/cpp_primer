/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.47: Explain whether the Sales_data constructor that takes a
string should be explicit. What are the benefits of making the
constructor explicit? What are the drawbacks?

Answer:
https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.47.md

It should be explicit. Otherwise, code like item.combine("9-999-99999-9") will
compile, but the code has no logical meaning.

Making the constructor explicit will stop compiler from automatically converting
one type to the class type, which makes the code same as anticipation.

The drawback is we must call the constructor explicitly if we want to cover one
type to the class type.

*/
