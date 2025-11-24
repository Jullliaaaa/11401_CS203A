/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/22: Initial implementation
    - 2025/11/24: Added basic hash function

   Developer: Miao-Xuan Xiao <s1113353@mail.yzu.edu.tw>
 */

#include "hash_fn.h"

// Basic integer  hash function using simple modulo (division) method.
int myHashInt(int key, int m) 
{
    return key % m;  // division method example
}


// Basic string hash function using simple ASCII sum.
int myHashString(const char* str, int m) 
{
    unsigned long hash = 0;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        hash += (unsigned char)str[i];   // add ASCII value of each char 
    }
    return (int)(hash % m); // basic division method
}
