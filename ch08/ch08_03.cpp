/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 8. The IO Library

Section 8.1 The IO Classes
Section 8.2 File Input and Output
Section 8.3 string Streams
******************************************************************************/

/*
  sstream strm    strm is an unbound stringstream
                  sstream is one of the types defined in the sstrea, header
  sstream strm(s) strm is an sstream that holds a copy of the string s.
                  this constructor is explicit.
  strm.str()      returns a copy of the string that strm holds
  strm.str(s)     copies the string s into strm, returns void.

8.3.1. Using an istringstream

8.3.2. Using ostringstreams

    ```cpp
    for (const auto &entry : people) { // for each entry in people
      ostringstream formatted, badNums; // objects created on each loop
      for (const auto &nums : entry.phones) { // for each number
        if (!valid(nums)) {
          badNums << " " << nums; // string in badNums
        } else
          // ''writes'' to formatted's string
          formatted << " " << format(nums);
      }
      if (badNums.str().empty()) // there were no bad numbers
        os << entry.name << " " // print the name
           << formatted.str() << endl; // and reformatted numbers
      else // otherwise, print the name and bad numbers
        cerr << "input error: " << entry.name
             << " invalid number(s) " << badNums.str() <<
      endl;
    }
    ```

*/