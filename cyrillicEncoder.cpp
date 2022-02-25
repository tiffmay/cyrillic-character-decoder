#include "cyrillicEncoder.h"
#include "hashTable.h"
#include <iostream>
#include <cwctype>
using namespace std;

CyrillicEncoder::CyrillicEncoder(char* seq) {
    sequence = seq;
};

int CyrillicEncoder::convertAlphaNumToCyrillic(int asciiValue) {
    // cyrillic range = 1024 (0x400) to 1145 (0x0479)
    return asciiValue + 976;
};

string CyrillicEncoder::convertUnicodeToUtf8(int unicode) {
    string s;
    unsigned char firstByte = 192u | ((unicode >> 6u) & 0b111111);
    unsigned char secondByte = 128u | ((unicode % 64u) & 0b111111);
    s = firstByte;    
    s += secondByte;
    return s;
};

void CyrillicEncoder::encode() {
    int seqLen = strlen(sequence);
    string cyrillicStr;
    for(int i = 0; i < seqLen; i ++) {
        int asciiValue = sequence[i];
        if (!iswalnum(asciiValue)){
            cout << "NON ALPHA NUMERIC CHAR, " << char(asciiValue) << ", was used. Only use [0-9A-Za-z].\n";
            exit(1);
        }
        string cyrillic = table.getCyrillic(asciiValue);
        if (cyrillic == ""){
            int cyrillicUnicode = convertAlphaNumToCyrillic(asciiValue);
            cyrillic = convertUnicodeToUtf8(cyrillicUnicode);
            HashItem adding;
            adding.alphanum = asciiValue;
            adding.cyrillic = cyrillic;
            table.insertItem(adding);
        }
        cyrillicStr += cyrillic;


    }
    cout << cyrillicStr << "\n";
    table.printTable();
};
