/*
   ========================================
   hash_fn.cpp ??? implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/22: Initial implementation
    - 2025/11/24: Added basic hash function
    - 2025/11/26: Added multiplication & Jenkins integer hash, SDBM & BKDR string hash

   Developer: Miao-Xuan Xiao <s1113353@mail.yzu.edu.tw>
 */
#include "hash_fn.hpp"
#include <cstdint>

// =================== Integer Hash Functions ===================

// Jenkins-like integer hash
int myHashInt(int key, int m) 
{
    uint32_t x = key;
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
    float mul = key * 0.618033;
    float frac = mul - (int)mul;     // fractional part
    return (int)(m * frac);          // multiplication method
}

// division integer hash function
int myHashInt(int key, int m) 
{
    return key % m;  // basic division method
}
*****/


// =================== String Hash Functions ===================

//SDBM string hash function
int myHashString(const std::string& str, int m) 
{
    unsigned long hash = 0;

    for (unsigned char c : str)
    {
        hash = c + (hash << 6) + (hash << 16) - hash;
    }
    
    return hash % m;
}

/*****
//BKDR string hash function
int myHashString(const std::string& str, int m) 
{
    unsigned long seed = 131;
    unsigned long hash = 0;

    for (char c : str) 
    {
        hash = hash * seed + static_cast<unsigned char>(c);
    }

    return static_cast<int>(hash % m);  
}
 
//simple ASCII sum string hash function
int myHashString(const std::string& str, int m) 
{
    unsigned long hash = 0;

    for (char c : str) 
    {
        hash += static_cast<unsigned char>(c);  // add ASCII value of each char
    }

    return static_cast<int>(hash % m);  // basic division method
}
*****/