#include "cyrillicEncoder.h"
#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    if (argc == 1) {
        cout << "[ERROR] No alphanumeric sequence passed. Please pass a sequence. Example run: \"./encoder asdF45t\"\n";
        return(1);
    }
    cout << "Sequence: ";
    CyrillicEncoder encoder;
    
    for (int i = 1; i < argc; i++) {
        encoder.encode(argv[i]);
    }   
    encoder.printDecodeTable();

    return(0);
}
