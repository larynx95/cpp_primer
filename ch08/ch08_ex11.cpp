/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 8. The IO Library

Exercise 8.11: The program in this section defined its istringstream
object inside the outer while loop. What changes would you need to make if
record were defined outside that loop? Rewrite the program, moving the
definition of record outside the while, and see whether you thought of all
the changes that are needed.

https://github.com/chihyang/CPP_Primer/blob/master/chap08/Exer08_11.cpp

*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::string;
using std::vector;

struct PersonInfo {
  string name;
  vector<string> phones;
};

int main() {
  string line, word;  // will hold a line and word from input, respectively
  vector<PersonInfo> people;  // will hold all the records from the input
  istringstream record;       // move istringstream here
  // read the input a line at a time until cin hits end-of-file(or another
  // error)
  while (getline(cin, line)) {
    PersonInfo info;  // create an object to hold this record's data
    record.clear();   // WARNING: without this, we can only read one record,
                      // because after the first
    // iteration, fail and eofbit will be set
    record.str(line);  // copy a line we just read to record
    if (record.eof()) cout << "record eof" << endl;
    if (record.fail()) cout << "record fail" << endl;
    record >> info.name;            // read the name
    while (record >> word)          // read the phone numbers
      info.phones.push_back(word);  // and store them
    people.push_back(info);         // append this record to people
  }
  for (const auto &p : people) {
    cout << p.name << " ";
    for (const auto &num : p.phones) cout << num << " ";
    cout << endl;
  }
  return 0;
}