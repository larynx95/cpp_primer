/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 7. Classes

Section 7.1 Defining Abstract Data Types
Section 7.2 Access Control and Encapsulation
Section 7.3 Additional Class Features
Section 7.4 Class Scope
******************************************************************************/

/*
7.4.1. Name Lookup and Class Scope
- Name Lookup for Class Member Declarations
- Type Names Are Special

    ```cpp
    typedef double Money;

    class Account {
    public:
      Money balance() { return bal; } // uses Money from the outer scope
    private:
      typedef double Money; // error: cannot redefine Money
      Money bal;
      // ...
    };
    ```

- Normal Block-Scope Name Lookup inside Member Definitions

    ```cpp
    // note: this code is for illustration purposes only
    // and reflects bad practice
    // it is generally a bad idea
    // to use the same name for a parameter and a member

    int height; // defines a name subsequently used inside Screen

    class Screen {
    public:
      typedef std::string::size_type pos;
      void dummy_fcn(pos height) {
        cursor = width * height; // which height? the parameter
      }
    private:
      pos cursor = 0;
      pos height = 0, width = 0;
    };
    ```

*/

/*
Section 7.5 Constructors Revisited
Section 7.6 static Class Members
*/