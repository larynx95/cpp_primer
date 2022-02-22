/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 3. Strings, Vectors, and Arrays

Section 3.1 Namespace using Declarations
Section 3.2 Library string Type
******************************************************************************/

#include <cctype>
#include <cstring>
#include <iostream>
#include <string>  // string library

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  /********************************************************
   * 3.2.1. Defining and Initializing strings
   ********************************************************/

  // defining & initializing
  {
    string s1;           // default initialization; s1 is the empty string
    string s2 = s1;      // s2 is a copy of s1 (copy initialize)
    string s3 = "a";     // s3 is a copy of the string literal
    string s4("a");      // s4 is a copy of the string literal
    string s5(10, 'c');  // initialize s5 with n copies of the character 'c'
  }

  // ways to initilizing a string
  {
    string s1;            // default initialization, s1 is the empty string
    string s2(s1);        // s2 is a copy of s1
    string s3 = s1;       // == s2(s1), s2 is a copy of s1
    string s4("value");   // s3 is a copy of the string literal, not null
    string s5 = "value";  // == s3("value")
    string s6(10, 'c');   // initialize s4 with 10 copies of the character 'c'

    cout << "s1: " << s1 << endl;  // ""   (print nothing)
    cout << "s2: " << s2 << endl;  // ""   (print nothing)
    cout << "s3: " << s3 << endl;  // ""   (print nothing)
    cout << "s4: " << s4 << endl;  // "value"
    cout << "s5: " << s5 << endl;  // "value"
    cout << "s6: " << s6 << endl;  // "cccccccccc"

    // string comparison
    // a. (==) operator            : if equal, return true(1)
    // b. string::compare method   : if equal, return 0
    // c. cstring::strcmp function : if equal, return 0

    cout << "s1 == s2: " << (s1 == s2) << endl;            // 1, true, equal
    cout << "s1.compare(s2): " << s1.compare(s2) << endl;  // 0, equal

    std::string s7 = "abc";
    std::string s8 = "abc";
    cout << "s7 == s8: " << (s7 == s8) << endl;            // 1, true, equal
    cout << "s7.compare(s8): " << s7.compare(s8) << endl;  // 0, equal
  }

  // copy vs. direct initialization
  {
    // TODO: What is the differences between them?
    string s1 = "hiya";  // copy initialization
    string s2("hiya");   // direct initialization
    string s3(10, 'c');  // direct initialization
    string s4{10, 'c'};  // TODO: What it this?

    cout << "s1: " << s1 << endl;  // "hiya"
    cout << "s2: " << s2 << endl;  // "hiya"
    cout << "s3: " << s3 << endl;  // "cccccccccc"
    cout << "s4: " << s4 << endl;  // ""

    // initializing a variable from more than one value
    // s5 and s6 are initialized in the same way
    // create a temporary string
    // then copy it into new string variable (as below)
    // Both (a) and (b) are the same.

    // (a) has hidden mechanism as in the example (b)
    string s5(10, 'c');
    // (b) create temporary string and copy it
    string temp = string(10, 'c');
    string s6 = temp;
  }

  string s5 = "hiya";           // copy initialization
  string s6("hiya");            // direct initialization
  string s7(10, 'c');           // direct initialization; s7 is cccccccccc
  string s8 = string(10, 'c');  // copy initialization; s8 is cccccccccc
  string temp(10, 'c');         // temp is cccccccccc
  s8 = temp;                    // copy temp into s8
  // TODO: What is the difference bw C and C++?

  /********************************************************
  3.2.2. Operations on strings
  (Exercises 3.1 ~ 3.5)
  ********************************************************/

  /*
  os << s     : writes s onto output stream os, return os
  is >> s     : reads whitespace-separated string from is into s
  getline(is,s) : read a line from is into s, return is
  s.empty()   : return true if s is empty
  s.size()    : return the number of characters in s
  s[n]        : return a reference to the char at position n
  s1 + s2     : returns a concatenated string
  s1 = s2     : replace characters in s1 with a copy of s2
  s1 == s2    : check equality
  s1 != s2    : equlaity is case-sensitive
  <. <=. >,>= : case-sensitive comparison
  */

  // Reading and Writing string s
  {
    string s;  // empty string
    std::cout << "== reading & writing ==" << std::endl;
    std::cout << "Enter a string: ";
    std::cin >> s;                // read a whitespace-separated string into s
    std::cout << s << std::endl;  // write s to the output
  }

  // multiple read & write
  {
    string s1, s2;
    std::cout << "== multiple read & write ===" << std::endl;
    std::cout << "Enter two strings: ";
    std::cin >> s1 >> s2;  // read first input into s1, second into s2
    std::cout << s1 << s2 << std::endl;  // write both strings
  }

  // Reading an Unknown Number of strings
  {
    string word;
    std::cout << "== reading a string with unknown length ==" << std::endl;
    std::cout << "Enter a string or strings: ";

    while (std::cin >> word) {
      // read until end-of-file
      std::cout << word << std::endl;  // write each word followed by a new line
      if (word == "quit") break;       // exit while-loop
    }
  }

  // Using getline to Read an Entire Line
  {
    string line;
    std::cout << "== getline ==" << std::endl;
    std::cout << "Enter a line or lines of string: ";

    // read input a line at a time until end-of-file
    while (getline(cin, line)) {
      std::cout << line << std::endl;  // print line
      if (line == "quit") break;       // exit while-loop
    }
  }

  // The string empty and size Operations
  {
    string line;
    std::cout << "== empty string ==" << std::endl;
    std::cout << "Enter a line or lines of string: ";

    while (getline(cin, line)) {
      if (!line.empty()) cout << line << endl;  // print
      if (line == "quit") break;                // exit while-loop
    }
  }

  // read string with given length
  {
    // read input a line at a time and print lines
    // that are longer than 80 characters
    // size() returns unsigned integer value
    string line;
    std::cout << "== string with given length ==" << std::endl;
    std::cout << "Enter a line or lines of string: ";

    while (getline(cin, line)) {
      if (line.size() > 10) cout << line << endl;
      if (line == "quit") break;
    }
  }

  // string::size_type type
  {
    string line;
    auto len = line.size();  // len has type string::size_type
    std::cout << "Type of len: " << typeid(len).name() << std::endl;
  }

  // comparing strings: length(size) --> each character
  {
    string s = "Hello";
    string s_up = "HELLO";
    string s_lo = "hello";
    cout << "== comparison ==" << endl;
    cout << "s == s_up: " << (s == s_up) << endl;        // 0
    cout << "s == s_lo: " << (s == s_lo) << endl;        // 0
    cout << "s_up == s_lo: " << (s_up == s_lo) << endl;  // 0
    cout << "s <= s_up: " << (s <= s_up) << endl;

    // compare (a) size, then (b) each character
    string str = "Hello";
    string phrase = "Hello World";
    string slang = "Hiya";
    cout << "str == phrase: " << (str == phrase) << endl;  // 0
    cout << "str == slang: " << (str == slang) << endl;    // 0
    cout << "str < phrase: " << (str < phrase) << endl;    // 1
    cout << "str < slang: " << (str < slang) << endl;      // 1
  }

  // assignment for strings
  {
    string st1(10, 'c'), st2;  // st1 is cccccccccc; st2 is an empty string
    st1 = st2;  // assignment: replace contents of st1 with a copy of st2
                // both st1 and st2 are now the empty string
  }

  // adding two strings
  {
    string s1 = "hello, ", s2 = "world\n";
    string s3 = s1 + s2;  // s3 is hello, world\n
    s1 += s2;             // equivalent to s1 = s1 + s2
  }

  // adding literals and strings
  {
    string s1 = "hello", s2 = "world";  // no punctuation in s1 or s2
    string s3 = s1 + ", " + s2 + '\n';

    // When we mix strings and string or character literals,
    // at least one operand to each + operator must be of string type

    string s4 = s1 + ", ";  // ok, adding a string and a literal
    // string s5 = "hello" + ", ";    // TODO: error: no string operand
    //             -------   ----     // only two string literals
    //                                // string literal doesn't have + operator
    string s6 = s1 + ", " + "world";  // ok: each + has a string operand
    //          --   ----   -------   // s1 is string type
    //                                // so this expression is ok
    // == (s1 + ", ") + "world"       // same expression
    //    -----------   -------       // first part is string
    // string s7 = "hello" + ", " + s2;  // TODO: error
    //             -------   ----   ---  // string literal doesn't have + op
    // == ("hello" + ", ") + s2
    //    ----------------               // this part is not working
  }

  /********************************************************
  3.2.3. Dealing with the Characters in a string
  (Exercise 3.6 ~ 3.11)
  ********************************************************/

  // dealing with characters in a string - cctype library
  {
      /*
      <cctype> header
      isalnum(c)   true if c is a letter or a digit
      isalpha(c)   true if c is a letter
      iscntrl(c)   true if c is a control character
      isdigit(c)   true if c is a digit
      isgraph(c)   true if c is not a space but is printable
      islower(c)   true if c is a lowercase letter
      isprint(c)   true if c is a printable character
      ispunct(c)   true if c is a puncutation character
      isspace(c)   true if c is whitespace
      isxdigit(c)  true if c is a hexadecimal digit
      tolower(c)   returns its lowercase
      toupper(c)   returns its uppercase
      */
  }

  // processing ecery characters - use range-based for-loop
  {
    string str("some string");
    // print the characters in str one character to a line
    for (auto c : str)   // for every char in str
      cout << c << " ";  // print the current character followed by a newline

    // punct_cnt has the same type that s.size returns; see § 2.5.3 (p. 70)
    decltype(str.size()) punct_cnt = 0;
    // count the number of punctuation characters in s
    for (auto c : str)  // for every char in s
      if (ispunct(c))   // if the character is punctuation
        ++punct_cnt;    // increment the punctuation counter

    cout << endl << punct_cnt << " punctuation characters in " << str << endl;
  }

  // using a range for-loop to change the characters in a string
  {
    string str("Hello World!!!");
    // convert s to uppercase
    // modifying original string value
    for (auto &c : str)  // for every char in s (note: c is a reference)
      c = toupper(c);

    // c is a reference, so the assignment changes the char in str

    cout << endl << str << " ";
  }

  // processing only some characters
  {
    string str = "abc";

    // make sure there's a character to print
    if (!str.empty())
      cout << "str[0]: " << str[0] << endl;  // print the first character in s
  }

  // using a subscript for iteration
  {
    string s = "some string";

    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]);
         ++index)
      s[index] = toupper(s[index]);  // capitalize the current character

    cout << "s: " << s << endl;  // SOME string
  }

  // using a subscript for Random access
  {
    const string hexdigits = "0123456789ABCDEF";  // possible hex digits
    cout << "Enter a series of numbers between 0 and 15"
         << " separated by spaces. Hit ENTER when finished: " << endl;
    string result;        // will hold the resulting hexify'd string
    string::size_type n;  // hold numbers from the input
    while (cin >> n) {
      if (n < hexdigits.size())  // ignore invalid input
        result += hexdigits[n];  // fetch the indicated hex digit
    }
    cout << "Your hex number is: " << result << endl;
  }

  return 0;
}

/*
Section 3.3 Library vector Type
Section 3.4 Introducing Iterators
Section 3.5 Arrays
Section 3.6 Multidimensional Arrays
*/