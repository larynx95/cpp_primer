/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.42: For the class you wrote for exercise 7.40 in § 7.5.1 (p. 291),
decide whether any of the constructors might use delegation. If so, write the
delegating constructor(s) for your class. If not, look at the list of
abstractions and choose one that you think would use a delegating constructor.
Write the class definition for that abstraction.

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.42.md
*/

#include <iostream>
#include <vector>
using namespace std;

class Book {
 public:
  // Book() : isbn(""), name(""), author(),
  //    publish_year(0), publisher(""), version(0) {}
  Book() : Book("", "", std::vector<std::string>(), 0, "", 0) {}
  Book(const std::string &i, const std::string &n,
       const std::vector<std::string> &au, unsigned y,
       const std::string &p = "", unsigned v = 1)
      : isbn(i),
        name(n),
        author(au),
        publish_year(y),
        publisher(p),
        version(v) {}
  Book(std::istream &is) {
    is >> isbn >> name;
    std::string s;
    is >> s;
    author.push_back(s);
    is >> publish_year >> publisher >> version;
  }

 private:
  std::string isbn;
  std::string name;
  std::vector<std::string> author;
  unsigned publish_year;
  std::string publisher;
  unsigned version;
};

int main() {
  //
  return 0;
}