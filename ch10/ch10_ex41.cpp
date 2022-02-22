/*
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 10. Generic Algorithms

Exercise 10.41: Based only on the algorithm and argument names, describe
the operation that the each of the following library algorithms performs:

replace(beg, end, old_val, new_val);
replace_if(beg, end, pred, new_val);
replace_copy(beg, end, dest, old_val, new_val);
replace_copy_if(beg, end, dest, pred, new_val);

Answer:
        replace(beg, end, old_val, new_val);

It replaces every element in the range [beg, end] that matches (==) old_val with
new_val.

        replace_if(beg, end, pred, new_val);

It replaces every element in the range [beg, end] that matches old_val with
new_val according to the predicatate (passed callable) condition.

        replace_copy(beg, end, dest, old_val, new_val);

The same as replace but copies the result of the operation to the destination
itrator (dest) and leaves the values in the range denoted by [beg, end] intact.

        replace_copy_if(beg, end, dest, pred, new_val);

The same as replace_if but copies the result of the operation to the destination
itrator (dest) and leaves the values in the range denoted by [beg, end] intact.

*/