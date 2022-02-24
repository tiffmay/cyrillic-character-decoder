#include "cyrillicEncoder.h"
#include <iostream>
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
    for(int i= 48; i < 58; i++){
        int cyrillicUnicode = convertAlphaNumToCyrillic(i);
        cout << "i=" << i <<" (" << char(i) << ") ascii=" << cyrillicUnicode << " cyrillic=" << convertUnicodeToUtf8(cyrillicUnicode) << "\n";
    }
    int A = 'A';
    int Z = 'Z';
        for(int i= A; i < Z+1; i++){
        int cyrillicUnicode = convertAlphaNumToCyrillic(i);
        cout << "i=" << i <<" (" << char(i) << ") ascii=" << cyrillicUnicode << " cyrillic=" << convertUnicodeToUtf8(cyrillicUnicode) << "\n";
    }

    int a = 'a';
    int z = 'z';
        for(int i= a; i < z+1; i++){
        int cyrillicUnicode = convertAlphaNumToCyrillic(i);
        cout << "i=" << i <<" (" << char(i) << ") ascii=" << cyrillicUnicode << " cyrillic=" << convertUnicodeToUtf8(cyrillicUnicode) << "\n";
    }

};
