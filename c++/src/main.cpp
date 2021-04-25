#include "sudoku.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {

    // Check input size
    if (argc != 2) {
        std::cout << "usage: sudoku filepath\n";
        return 1;
    }

    Sudoku test(argv[1]);
    if (test.solve()) std::cout << test;
    else std::cout << "Impossible to solve!";

    return 0;
}