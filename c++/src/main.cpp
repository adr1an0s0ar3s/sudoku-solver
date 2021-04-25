#include "sudoku.h"
#include <iostream>

int main() {

    // TODO: Read board from a file
    int board[9][9] = {{0,0,0,0,9,0,0,2,0}
                      ,{4,0,2,5,0,0,0,6,0}
                      ,{0,5,3,0,7,0,0,4,0}
                      ,{0,7,8,0,0,1,0,0,0}
                      ,{9,0,0,0,5,0,0,0,0}
                      ,{0,4,0,6,0,0,0,0,0}
                      ,{0,0,0,0,0,7,0,0,2}
                      ,{5,0,0,0,4,0,7,0,0}
                      ,{0,0,0,0,0,0,1,0,6}};

    Sudoku test(board);

    // TODO: Create a print() method
    std::cout << test.solve() << std::endl;
}