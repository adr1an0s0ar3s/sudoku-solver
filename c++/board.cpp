#include "board.h"

#include <vector>

Board::Board(std::vector<std::vector<int>> &board) {
    int size = board.size(), value;
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            value = board[row][column];
            this->board[row][column] = value;
            columns[column][value] = true;
            rows[row][value] = true;
        }
    }
}