/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Section 9.1 Overview of the Sequential Containers
Section 9.2 Container Library Overview
Section 9.3 Sequential Container Operations
Section 9.4 How a vector Grows
Section 9.5 Additional string Operations
******************************************************************************/

/*
9.5.1. Other Ways to Construct strings

  string s(cp,n)         s is a copy of the first n characters in the array
                         to which cp points.
  string s(s2,pos2)      s is a copy of the characters in the string s2
                         starting at the index pos2
  string s(s2,pos2,len2) s is a copy of len2 characters from s2
                         starting at the index pos2

- The substr Operation

9.5.2. Other Ways to Change a string

- The append and replace Functions
- TODO: Summarize this later!!
- The Many Overloaded Ways to Change a string

9.5.3. string Search Operations

- Specifying Where to Start the Search
- Searching Backward

9.5.4. The compare Functions

9.5.5. Numeric Conversions

*/

#include <iostream>
#include <string>
using namespace std;

int main() {
  const char *cp = "Hello World!!!";  // null-terminated array
  char noNull[] = {'H', 'i'};         // not null terminated
  string s1(cp);         // copy up to the null in cp; s1 == "Hello World!!!
  string s2(noNull, 2);  // copy two characters from no_null; s2 == "Hi"
  string s3(noNull);     // undefined: noNull not null terminated
  string s4(cp + 6, 5);  // copy 5 characters starting at cp[6]; s4 == "World"
  string s5(s1, 6, 5);   // copy 5 characters starting at s1[6]; s5 == "World"
  string s6(s1, 6);      // copy from s1 [6] to end of s1; s6 == "World!!!"
  string s7(s1, 6, 20);  // ok, copies only to end of s1; s7 == "World!!!"
  // string s8(s1, 16);     // throws an out_of_range exception

  cout << s1 << endl;  // Hello World!!!
  cout << s2 << endl;  // Hi
  cout << s3 << endl;  // Hi□  TODO: what is the symbol at the end of this?
  cout << s4 << endl;  // World
  cout << s5 << endl;  // World
  cout << s6 << endl;  // World!!!
  cout << s7 << endl;  // World!!!

  /* substr() function */
  string str("hello world");
  string str2 = str.substr(0, 5);   // str2 = hello
  string str3 = str.substr(6);      // str3 = world
  string str4 = str.substr(6, 11);  // str3 = world
  // string str5 = str.substr(12);     // throws an out_of_range exception

  str.insert(str.size(), 5, '!');  // insert five ! points at the end of s
  str.erase(str.size() - 5, 5);    // erase the last five characters from s
  cout << str << endl;

  const char *cp2 = "Stately, plump Buck";
  string str5;
  str5.assign(cp2, 7);  // s == "Stately"
  cout << str5 << endl;
  str5.insert(str5.size(), cp2 + 7);  // s == "Stately, plump Buck"
  cout << str5 << endl;

  string text1 = "some string", text2 = "some other string";
  text1.insert(0, text2);  // insert a copy of text2 before position 0 in text1
  // insert text2.size() characters from text2 starting at text2[0] before
  // text1[0]
  cout << "text1=" << text1 << ",  text2=" << text2 << endl;
  text1.insert(0, text2, 0, text2.size());
  cout << "text1=" << text1 << ",  text2=" << text2 << endl;

  return 0;
}

/*
Section 9.6 Container Adaptors

*/