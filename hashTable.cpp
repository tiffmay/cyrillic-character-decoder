#include "hashTable.h"

HashTable::HashTable(){
    table = new list<HashItem>[BUCKET];
}

int HashTable::hashFunction(int item){
    return item % BUCKET;
}

void HashTable::insertItem(HashItem item){
    int index = hashFunction(item.alphanum);
    table[index].push_back(item);
}

string HashTable::getCyrillic(int alphanum){
    int index = hashFunction(alphanum);
    for (auto &item: table[index]) {
        if (item.alphanum == alphanum) return item.cyrillic;
    }
    return "";
}

void HashTable::printTable(){
    cout << "--[ ENCODING TABLE ]--\n";
    cout << "----------------------\n";
    for (int i = 0; i < BUCKET; i++) {
        for (auto &item: table[i]) {
            cout << "|        " << char(item.alphanum) << " = " << item.cyrillic << "       |\n";
        }
    }
    cout << "----------------------\n";
}
