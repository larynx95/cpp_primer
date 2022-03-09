/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 11. Associative Containers

Exercise 11.6:
Explain the difference between a set and a list. When might you use
one or the other?
******************************************************************************/

/*
https://www.geeksforgeeks.org/difference-between-stdset-and-stdlist/
set
1	Set is sorted and unordered
2	Insertion cannot be done at the desired position
3	Takes logarithmic time for searching an element.
4	Elements are unique.
5	Can contain only one null value.
6	Insertion and deletion take logarithmic time.
7	Implemented in HashSet, LinkedHashSet, and TreeSet.

List
1	SThe list is unsorted and ordered
2 Insertion can be done at any position using the insert() function
3	Takes linear time for searching for an element.
4	May contain duplicate elements.
5	Can contain more than one null value.
6	Insertion and deletion take constant time.
7	Implemented in ArrayList and LinkedList

*/
