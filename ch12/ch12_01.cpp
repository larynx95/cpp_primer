/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 12. Dynamic Memory

Section 12.1 Dynamic Memory and Smart Pointers
  12.1.1 The shared_ptr Class
    The make_shared function
    Copying and assigning shared_ptrs
    shared_ptr automatically destroy their objects ...
    ... and Automatically Free the Associated Memory
************************************************/

#include <iostream>
#include <list>
#include <memory>
#include <vector>

using namespace std;

int main() {
  /* shared_prt */
  {
    // declaring shared_ptr pointing at a string
    std::shared_ptr<std::string> p1;
    // shared_ptr pointing at a list of ints
    std::shared_ptr<std::list<int>> p2;
    // if p1 is not null, check whether it's the empty string
    if (p1 && p1->empty()) {
      *p1 = "hi";
    }
  }

  /* the make_shared function */
  {
    // shared_ptr that points to an int with value 42
    shared_ptr<int> p3 = make_shared<int>(42);
    // p4 points to a string with value 9999999999
    shared_ptr<string> p4 = make_shared<string>(10, '9');
    // p5 points to an int that is value initialized (§ 3.3.1 (p. 98)) to 0
    shared_ptr<int> p5 = make_shared<int>();
    // p6 points to a dynamically allocated, empty vector<string>
    auto p6 = make_shared<vector<string>>();
  }

  /* Copying and assigning shared_ptrs */
  {
    auto p = make_shared<int>(42);  // object to which p points has one user
    auto q(p);                      // p and q point to the same object
    // object to which p and q point has two users
  }

  /*
  Table 12.1: Operations Common to shared_ptr and unique_ptr
  shared_ptr<T> sp  Null smart pointer that can point to objects of type T.
  unique_ptr<T> up
  p                 Use p as a condition; true if p points to an object.
  *p                Dereference p to get the object to which p points.
  p->mem            Synonym for (*p).mem.
  p.get()           Returns the pointer in p.
                    Use with caution;
                    the object to which the returned pointer points
                    will disappear when the smart pointer deletes it.
  swap(p, q)        Swaps the pointers in p and q.
  p.swap(q)
  */

  /* reference count */
  {
    // std::shared_ptr<T>::use_count
    // https://en.cppreference.com/w/cpp/memory/shared_ptr/use_count

    auto sp1 = std::make_shared<int>(5);
    std::cout << "in main(): sp1.use_count() == " << sp1.use_count()
              << " (object @ " << sp1 << ")\n";
    fun(sp1);
    // in main(): sp1.use_count() == 1 (object @ 0x555555570ec0)
    // in fun(): sp.use_count() == 2 (object @ 0x555555570ec0)
  }

  /* automatic freeing */
  {
    std::shared_ptr<int> sp;  // empty
    std::shared_ptr<int> sp2;
    std::cout << "sp.use_count(): " << sp.use_count() << std::endl;    // 0
    std::cout << "sp2.use_count(): " << sp2.use_count() << std::endl;  // 0

    sp.reset(new int);
    sp2.reset(new int);
    std::cout << "sp.use_count(): " << sp.use_count() << std::endl;    // 1
    std::cout << "sp2.use_count(): " << sp2.use_count() << std::endl;  // 1

    *sp = 10;
    *sp2 = 400;
    sp2 = sp;
    std::cout << "sp.use_count(): " << sp.use_count() << std::endl;    // 2
    std::cout << "sp2.use_count(): " << sp2.use_count() << std::endl;  // 2

    std::shared_ptr<int> sp3;
    std::cout << "sp.use_count(): " << sp.use_count() << std::endl;    // 2
    std::cout << "sp2.use_count(): " << sp2.use_count() << std::endl;  // 2
    std::cout << "sp3.use_count(): " << sp3.use_count() << std::endl;  // 0
    sp3 = sp;
    std::cout << "sp.use_count(): " << sp.use_count() << std::endl;    // 3
    std::cout << "sp2.use_count(): " << sp2.use_count() << std::endl;  // 3
    std::cout << "sp3.use_count(): " << sp3.use_count() << std::endl;  // 3

    shared_ptr<int> q;
    auto r = make_shared<int>(42);  // int to which r points has one user
    std::cout << "r.use_count(): " << r.use_count() << std::endl;  // 1
    r = q;
    // assign to r, making it point to a different address
    // increase the use count for the object to which q points
    // reduce the use count of the object to which r had pointed
    // the object r had pointed to has no users; that object is automatically
    // freed
    std::cout << "r.use_count(): " << r.use_count() << std::endl;  // 0
  }

  /*
  Table 12.2: Operations Specific to shared_ptr
  make_shared<T>(args)    Returns a shared_ptr pointing to a dynamically
                          allocated object of type T.
                          Uses args to initialize that object.
  shared_ptr<T> p(q)      p is a copy of the shared_ptr q;
                          increments the count in q.
                          The pointer in q must be convertible to
                          T* (§ 4.11.2, p. 161).
  p=q                     p and q are shared_ptrs holding pointers
                          that can be converted to one another.
                          Decrements p’s reference count
                          and increments q’s count;
                          deletes p’s existing memory
                          if p’s count goes to 0.
  p.unique()              Returns true if p.use_count() is one;
                          false otherwise.
  p.use_count()           Returns the number of objects sharing with p;
                          may be a slow operation,
                          intended primarily for debugging purposes.
  */

  /* copying vector */
  {
    vector<string> v1;  // empty vector
    {
      vector<string> v2 = {"a", "an", "the"};
      v1 = v2;  // copies the elements from v2 into v1
    }           // v2 is destroyed, which destroys the elements in v2
    // v1 has three elements, which are copies of the ones originally in v2
    print_vec(v1);  // a an the
  }
  return 0;
}