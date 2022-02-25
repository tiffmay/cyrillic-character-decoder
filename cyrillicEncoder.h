using namespace std;
#include "hashTable.h"
#include <iostream>
#include <cstring>

#ifndef CYRILLIC_ENCODER_H
#define CYRILLIC_ENCODER_H

class CyrillicEncoder
{
    HashTable table;
    int convertAlphaNumToCyrillic(int asciiValue);
    string convertUnicodeToUtf8(int unicode); 
    string getCyrillic(int alphanum);
    void updateTable(int alphanum, string cyrillic);
public:
    void encode(char* sequence);
    void printDecodeTable();
};

#endif
