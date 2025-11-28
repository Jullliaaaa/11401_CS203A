/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/22: Initial implementation
    - 2025/11/24: Added basic hash function
    - 2025/11/26: Added multiplication & Jenkins integer hash, SDBM & BKDR string hash

   Developer: Miao-Xuan Xiao <s1113353@mail.yzu.edu.tw>
 */

#include "hash_fn.h"

#include <stdint.h>

// ================= Integer Hash Functions =================

// Jenkins-like integer hash
int myHashInt(int key, int m) 
{
    uint32_t x = (uint32_t)key;
    x += (x << 11);
    x ^= (x >> 13);
    x += (x << 6);
    x ^= (x >> 10);
    x += (x << 15);
    return x % m;  
}

/***** 
// multiplication integer hash function
int myHashInt(int key, int m) 
{
    float mul = key * 0.618033f;
    float frac = mul - (int)mul;     
    return (int)(m * frac);          
}

// division integer hash function
int myHashInt(int key, int m) 
{
    return key % m;  // basic division method
}
*****/

// ================= String Hash Functions =================

// SDBM string hash function
int myHashString(const char* str, int m) 
{
    unsigned long hash = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)str[i];
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    return (int)(hash % m);
}

/***** 
// BKDR string hash function
int myHashString(const char* str, int m) 
{
    unsigned long seed = 131;
    unsigned long hash = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)str[i];
        hash = hash * seed + c;
    }

    return (int)(hash % m);  
}

//simple ASCII sum string hash function
int myHashString(const char* str, int m) 
{
    unsigned long hash = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)str[i];
        hash += c;
    }

    return (int)(hash % m);  // basic division method
}
*****/
