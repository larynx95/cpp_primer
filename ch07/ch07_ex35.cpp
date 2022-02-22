/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 07. Classes

Exercise 7.35: Explain the following code, indicating which definition of
Type or initVal is used for each use of those names. Say how you would
fix any errors.

    typedef string Type;
    Type initVal();

    class Exercise {
    public:
      typedef double Type;
      Type setVal(Type);
      Type initVal();
    private:
      int val;
    };

    Type Exercise::setVal(Type parm) {
      val = parm + initVal();
      return val;
    }

https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch7/7.35.cpp
*/

#include <string>

typedef std::string Type;

Type initVal();  // std::string

class Exercise {
 public:
  typedef double Type;
  Type setVal(Type);  // double setVal(double)
  Type initVal();     // double initVal()
 private:
  int val;
};

Exercise::Type Exercise::setVal(Type parm) {
  // double Exercise::setVal(double para)
  // Type Exercise::setVal(Type parm) {  // Error: int Exercise::setVal(double
  // para)
  val = parm + initVal();
  return val;
}

Exercise::Type Exercise::initVal() { return 0; }

int main() { return 0; }
