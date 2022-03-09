/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 12. Dynamic Memory

Exercise 12.1:
How many elements do b1 and b2 have at the end of this code?

StrBlob b1;
{
  StrBlob b2 = {"a", "an", "the"};
  b1 = b2;
  b2.push_back("about");
}
************************************************/

/*
Answer:
b1 has 4 and b2 is destroyed.
*/
