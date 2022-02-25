using namespace std;
#include <iostream>
#include <cstring>
#include <list>

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct HashItem HashItem;
struct HashItem {
    int alphanum;
    string cyrillic;
};

class HashTable
{
    int BUCKET = 16; //62 alphanumberic characters
    list<HashItem> *table;

public:
    HashTable();
    void insertItem(HashItem item);
    string getCyrillic(int alphanum);
    int hashFunction(int item);
    void printTable();
};

#endif
