#include <iostream>

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "No alphanumeric sequence passed. Please pass one sequence. Example run: \"main asdf45t\"\n";
        return(1);
    }
    if (argc > 2) {
        std::cout << "More than one alphanumeric sequence passed. Please pass only one sequence. Example run: \"main asdf45t\"\n";
        return(1);
    }

    char *sequence = argv[1];
    std::cout << "sequence = " << sequence << "\n";
    return(0);
}
