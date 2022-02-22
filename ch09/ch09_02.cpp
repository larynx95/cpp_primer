/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 9. Sequential Containers

Section 9.1 Overview of the Sequential Containers
  - Constraints on Types That a Container Can Hold
Section 9.2 Container Library Overview
******************************************************************************/

/*
Table 9.2. Container Operations
Type Aliases:
interator         Type of the interator for this container type
const_interator   Iterator type that can read but not change its elements
size_type         Unsigned integral type big enough to hold the
                  size of the largest possible container of this container type
difference_types  Signed integral type big enough to hold
                  the distance between two interators
value-type        Element type
reference         Element's lvalue type; synonym for value_type&
const_reference   Element's const lvalue type (i.e., const va;lue_type&)

Construction:
C c;              Defalut constructor, empty container(array)
C c1(c2);         Construct c1 as a copy of c2
C c(b, e);        Copy elements from the range denoted by iterators b and e;
                  (not valid for array)
C c(a, b, c ...)  List initialize c

Assignment and swap:
c1 = c2           Replace elements in c1 with those in c2
c1 = {a,b,c...}   Replace elements in c1 with those in the list
                  (not valid for array)
a.swap(b)         Swap elements in a with those in b
swap(a,b)         Equivalent to a,swap(b)

Size:
c.size()          Number of elements in c (not valid for forward_list)
c.max_size()      Maximum number of elements c can hold
c.empty()         false if c has any elements, true otherwise

Add/Remove Elements (not valid for array):
Note: the interface to these operations varies by container type
c.insert(args)    Copy element(s) as specified by args into c
c.emplace(inits)  use inits to construct an element in c
c.erase(args)     Remove element(s) specified by args
c.clear()         Remove all elements from c; return void

Equality and Relational Operators:
==, !=            Equality valid for all container types
<, <=, >, >=      Relationals (not valid for unordered associative containers)

Obtain Iterators:
c.begin()         Equality valid for all container types
c.end()
c.cbegin()        Relationals (not valid for unordered associative containers)
c.cend()

Additional Members of Reversible Containers (not valid for forward_list):
reverse_iterator       Iterator that addresses elements in reverse order
const_reverse_iterator Reverse iterator that cannot wirte the elements
c.rbegin(), c.rend()   Return iterator to the last,
                       one past the first element in c
c.crbegin(), c.crend() Return const_reverse_interator

Table 9.3. Defining and Initializing Containers
C c;             Default constructor. If C is array, then the elems in c are
                 default-initialized; otherwise c is empty
C c1(c2)         c1 is a copy of c2. c1 and c2 must have the same type
C c1 = c2        (i.e., they must be the same container type
                 and hold the same elemen type;
                 for array must also have the same size)
C c{a,b,c...}    c is a copy of the elements in the initializer list.
C c = {a,b,c...} Type of elements in the list must be compatible with
                 the element type of C.
                 For arraym the list must have same number or fewer elements
                 than the size of the array,
                 any missing elements are value-initialized
C c(b,e)         c is a copy of the elements in the range denoted
                 by interators b and e.
                 Type of the elements must be compatible with
                 the element type of C. (Not valid for array)
Constructors that take a size are valid for sequential containers
(not including array) only:
C seq(n)         seq has n value-initialized elements;
                 this constructor is explicit
C seq(n, t)      seq has n elements with value t

9.2.1. Iterators

- Iterator Ranges: `[ begin, end)`, left-includsive
  indicating that the range begins with begin and ends with,
  but does not include, end.

- Programming Implications of Using Left-Inclusive Ranges
  - If begin equals end, the range is empty
  - If begin is not equal to end, there is at least one element in the range,
    and begin refers to the first element in that range
  - We can increment begin some number of times until begin == end

9.2.2. Container Type Members

9.2.3. begin and end Members

    ```cpp
    list<string> a = {"Milton", "Shakespeare", "Austen"};
    auto it1 = a.begin(); // list<string>::iterator
    auto it2 = a.rbegin(); // list<string>::reverse_iterator
    auto it3 = a.cbegin(); // list<string>::const_iterator
    auto it4 = a.crbegin();// list<string>::const_reverse_iterator
    ```

9.2.4. Defining and Initializing a Container

- Initializing a Container as a Copy of Another Container

- List Initialization

- Sequential Container Size-Related Constructors

9.2.5. Assignment and swap

- Using assign (Sequential Containers Only)
- Using swap

9.2.6. Container Size Operations

9.2.7. Relational Operators

*/

#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  // each container has three elements, initialized from the given initializers
  list<string> authors = {"Milton", "Shakespeare", "Austen"};
  vector<const char*> articles = {"a", "an", "the"};
  list<string> list2(authors);  // ok: types match
  // deque<string> authList(authors);  // error: container types don't match
  // vector<string> words(articles);   // error: element types must match
  // ok: converts const char* elements to string
  forward_list<string> words(articles.begin(), articles.end());

  return 0;
}

/*
Section 9.3 Sequential Container Operations
Section 9.4 How a vector Grows
Section 9.5 Additional string Operations
Section 9.6 Container Adaptors

*/