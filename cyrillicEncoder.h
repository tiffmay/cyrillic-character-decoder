using namespace std;
#include "hashTable.h"
#include <iostream>
#include <cstring>

#ifndef CYRILLIC_ENCODER_H
#define CYRILLIC_ENCODER_H

class CyrillicEncoder
{
    char* sequence;
    HashTable table;
public:
    CyrillicEncoder(char* seq);
    int convertAlphaNumToCyrillic(int asciiValue);
    string convertUnicodeToUtf8(int unicode); 
    void encode();
};

#endif
