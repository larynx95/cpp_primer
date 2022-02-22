/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.7: Determine if there are any errors in the following programs
and, if so, correct the error(s):

(a)
vector<int> vec; list<int> lst; int i;
while (cin >> i)
  lst.push_back(i);
copy(lst.cbegin(), lst.cend(), vec.begin());

(b)
vector<int> vec;
vec.reserve(10); // reserve is covered in § 9.4 (p. 356)
fill_n(vec.begin(), 10, 0);

Answer:
(a) vec is an empty vector, which means the algorith copy cannot write to it.
The size of lst is determined by the number of inputs from istream, which means
it is only known at runtime. We should use an insert iterator for vec if we
wanted to use copy:

        vector<int> vec; list<int> lst; int i;
        while (cin >> i)
                lst.push_back(i);
        copy(lst.cbegin(), lst.cend(), back_inserter(vec));

(b) The operation reserve sets the capacity, NOT the size, of vec to 10. We
would have to declare vec as a vector with size 10:

        vector<int> vec(10);
        fill_n(vec.begin(), 10, 0);

https://github.com/cdude996/Cpp-Primer/blob/master/chapter10/10.07.txt

*/