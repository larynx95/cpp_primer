/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 8. The IO Library
******************************************************************************/

/*
Section 8.1 The IO Classes
- IO library types and headers
  headers     type
  iostream    istream, wistream reads from a stream
              ostream, wostream writes to a stream
              iostream, wiostream reads and writes a stream
  fstream     ifstream, wifstream reads from a file
              ofstream, wofstream writes to a file
              fstream, wfstream reads and writes a file
  sstream     istringstream, wistringstream reads from a string
              ostringstream, wostringstream writes to a string
              stringstream, wstringstream reads and writes a string

- Relationships among the IO Types

8.1.1. No Copy or Assign for IO Objects

8.1.2. Condition States

  strm::iostate    strm is one of the IO types
                   iostate is a machine-dependent integral type
                   that represents the condition state of a stream
  strm::badbit     strm::iostate value used
                   to indicate that a stream is corrupted
  strm::failbit    strm::iostate value used
                   to indicate that an IO operation failed
  strm::eofbit     strm::iostate value used
                   to indicate that a stream hit end-of-file
  strm::goodbit    strm::iostate value used
                   to indicate that a stream is not in an error state.
                   This value is guaranteed to be zero.
  s.eof()          true if eofbit in the stream s is set
  s.fail()         true if failbit or badbit in the stream s is set
  s.bad()          true if badbit in the stream s is set
  s.good()         true if the stream s is in a valid state
  s.clear()        reset all condition values in the stream s
                   to valid state. return void.
  s.clear(flags)   reset the condition of s to flags.
                   type of flags is strm::iostate. return void.
  s.setstate(flags)add specified conditions to s.
                   type of flags is strm::iostate. returns void.
  s.rdstate()      return current condition fo s as a strm::iostate value.

8.1.3. Managing the Output Buffer

- Flushing the Output Buffer

- The `unitbuf` Manipulator

- Tying Input and Output Streams Together

*/

#include <iostream>
using namespace std;

int main() {
  cout << "hi!" << endl;   // writes hi and a newline, then flushes the buffer
  cout << "hi!" << flush;  // writes hi, then flushes the buffer; adds no data
  cout << "hi!" << ends;   // writes hi and a null, then flushes the buffer
  cout << unitbuf;         // all writes will be flushed immediately
  // any output is flushed immediately, no buffering
  cout << nounitbuf;  // returns to normal buffering

  cin.tie(&cout);  // illustration only: the library ties cin and cout for us
  // old_tie points to the stream (if any) currently tied to cin
  ostream *old_tie = cin.tie(nullptr);  // cin is no longer tied
  // ties cin and cerr; not a good idea because cin should be tied to cout
  cin.tie(&cerr);    // reading cin flushes cerr, not cout
  cin.tie(old_tie);  // reestablish normal tie between cin and cout

  return 0;
}

/*
Section 8.2 File Input and Output
Section 8.3 string Streams
*/