#include "cyrillicEncoder.h"
#include "hashTable.h"
#include <iostream>
#include <cwctype>
using namespace std;

int CyrillicEncoder::convertAlphaNumToCyrillic(int asciiValue) {
    // cyrillic range = 1024 (0x400) to 1145 (0x0479)
    return asciiValue + 977;
}

string CyrillicEncoder::convertUnicodeToUtf8(int unicode) {
    string s;
    unsigned char firstByte = 192u | ((unicode >> 6u) & 0b111111);
    unsigned char secondByte = 128u | ((unicode % 64u) & 0b111111);
    s = firstByte;    
    s += secondByte;
    return s;
}

string CyrillicEncoder::getCyrillic(int alphanum) {
    string cyrillic = table.getCyrillic(alphanum);
    if (cyrillic == "") {
        int cyrillicUnicode = convertAlphaNumToCyrillic(alphanum);
        cyrillic = convertUnicodeToUtf8(cyrillicUnicode);
        updateTable(alphanum, cyrillic);
    }
    return cyrillic;
}

void CyrillicEncoder::updateTable(int alphanum, string cyrillic) {
    HashItem adding;
    adding.alphanum = alphanum;
    adding.cyrillic = cyrillic;
    table.insertItem(adding);
}

void CyrillicEncoder::encode(char* sequence) {
    int seqLen = strlen(sequence);
    string cyrillicStr;
    for (int i = 0; i < seqLen; i++) {
        int alphanum = sequence[i];
        if (!iswalnum(alphanum)){
            cout << "[ERROR] NON-ALPHA-NUMERIC CHAR, " << char(alphanum) << ", was used. Only use [0-9A-Za-z].\n";
            exit(1);
        }
        cyrillicStr += getCyrillic(alphanum);
    }
    cout << cyrillicStr << " ";
}

void CyrillicEncoder::printDecodeTable(){
    cout << "\n\n";
    table.printTable();
}
