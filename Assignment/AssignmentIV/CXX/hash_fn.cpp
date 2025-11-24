/*
   ========================================
   hash_fn.cpp ??? implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/22: Initial implementation
    - 2025/11/24: Added basic hash function

   Developer: Miao-Xuan Xiao <s1113353@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"


// Basic integer hash function using simple modulo (division) method.
int myHashInt(int key, int m) 
{
    return key % m;  // basic division method
}

// Basic string hash function using simple ASCII sum.
int myHashString(const std::string& str, int m) 
{
    unsigned long hash = 0;
    for (char c : str) 
    {
        hash += static_cast<unsigned char>(c);  // add ASCII value of each char
    }
    return static_cast<int>(hash % m);  // basic division method
}
