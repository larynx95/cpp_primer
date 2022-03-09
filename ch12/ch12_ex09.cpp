/************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 12. Dynamic Memory

EExercise 12.9:
Explain what happens in the following code:

int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;

************************************************/

/*
        int *q = new int(42), *r = new int(100);

q and r are pointers to int pointing to memory blocks on the heap,
initialized with values 42 and 100 respectively.

        r = q;

r points at what q points: value 100. r's old object is "lost", but its memory
is not freed.

        auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);

q2 and r2 are shared smart pointers to int pointing to memory blocks on the
heap, initialized with values 42 and 100 respectively.

        r2 = q2;

r2 points to what q2 points to. r2's reference counter is decrement. It is now
zero, and therefore, its old object is destroyed and its memory is freed. q's
reference counter is incremented.

*/