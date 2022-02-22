/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.2: Indicate which of the following functions are in error and why.
Suggest how you might correct the problems.

(a)
int f() {
  string s;
  // ...
  return s;
}

(b)
f2(int i) { // ...  }

(c)
int calc(int v1, int v1) { // ...}

(d)
double square(double x) return x * x;

Answer:
(a)
//int f() {  // Return type doesn't match
string f() {
  string s;
  // ...
  return s;
}
TODO: Can local string be returned?

(b)
//f2(int i) { //... }  // Must have a return type
void f2(int i) { //... }

(c)
//int calc(int v1, int v1) //... }  // Forget begin brace `{`
int calc(int v1, int v1) { //... }

(d)
//double square(double x) return x * x;  // The function body should be a block.
double square(double x) { return x * x; }

*/