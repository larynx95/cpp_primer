/*
C++ Primer, Stanley B. Lippmann, 2013
Chapter 06. Functions

Exercise 6.19: Given the following declarations, determine which calls are
legal and which are illegal. For those that are illegal, explain why.
Click here to view code image
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator,
int);
vector<int> vec(10);
(a) calc(23.4, 55.1);
(b) count("abcda", 'a');
(c) calc(66);
(d) sum(vec.begin(), vec.end(), 3.8);


Answer:
(a) Illegal. Only one parameter is needed for the function.
(b) Legal. (c) Legal. (d) Legal.

*/