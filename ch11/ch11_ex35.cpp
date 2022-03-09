/******************************************************************************
C++ Primer 5th. edition, Stanley B. Lippmann, 2013
Chapter 11. Associative Containers

Exercise 11.35:
In buildMap, what effect, if any, would there be from rewriting
trans_map[key] = value.substr(1);
as trans_map.insert({key, value.substr(1)})?
******************************************************************************/
