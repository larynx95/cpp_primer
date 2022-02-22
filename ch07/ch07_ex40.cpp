/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.40: Choose one of the following abstractions (or an abstraction
of your own choosing). Determine what data are needed in the class. Provide
an appropriate set of constructors. Explain your decisions.

(a) Book
(b) Date
(c) Employee
(d) Vehicle
(e) Object
(f) Tree

Answer:
https://github.com/cdude996/Cpp-Primer/blob/master/chapter07/7.40.h
in the interest of brevity, our class has only 4 data members. The
set of constructors to initialize an object of the class is made up of the
default constructor, a constructor for an employee number, a constructor that
initializes the rest of the members, and finally an istream constructor. For
general initialization uses, this set should suffice. However, depending on
how we intend to create and initialize objects of this class in special case,
we would may need to add constructors or refine the existing ones.

*/

// https://github.com/chihyang/CPP_Primer/blob/master/chap07/Exer07_40_Book.h

#include <string>
#include <utility>

using std::string;
class Book {
 public:
  Book() = default;
  Book(string na, string au = "", string no = "")
      : book_name(na), book_author(au), book_no(no) {}
  // copy control constructor
  Book(const Book&) = default;  // copy constructor
  Book(Book&& b) noexcept
      :  // move constructor
        book_name(std::move(b.book_name)),
        book_author(std::move(b.book_author)),
        book_no(std::move(book_no)) {}
  Book& operator=(const Book&) = default;  // copy-assignment operator
  Book& operator=(Book&&) noexcept;        // move assignment operator
  ~Book() = default;

 private:
  string book_name;
  string book_author;
  string book_no;
};
Book& Book::operator=(Book&& rhs) noexcept {
  if (this != &rhs) {
    book_name = std::move(rhs.book_name);
    book_author = std::move(rhs.book_author);
    book_no = std::move(rhs.book_no);
  }
  return *this;
}