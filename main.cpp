#include "cyrillicEncoder.h"
#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    if (argc == 1) {
        cout << "No alphanumeric sequence passed. Please pass one sequence. Example run: \"main asdf45t\"\n";
        return(1);
    }
    if (argc > 2) {
        cout << "More than one alphanumeric sequence passed. Please pass only one sequence. Example run: \"main asdf45t\"\n";
        return(1);
    }

    CyrillicEncoder encoder(argv[1]);
    encoder.encode();
    return(0);
}
