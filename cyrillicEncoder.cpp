#include "cyrillicEncoder.h"
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
        if(!iswalnum(asciiValue)){
            cout << "NON ALPHA NUMERIC CHAR, " << char(asciiValue) << ", was used. Only use [0-9A-Za-z].\n";
            exit(1);
        }
        int cyrillicUnicode = convertAlphaNumToCyrillic(asciiValue);
        cyrillicStr += convertUnicodeToUtf8(cyrillicUnicode);
    }
    cout << cyrillicStr << "\n";
};
