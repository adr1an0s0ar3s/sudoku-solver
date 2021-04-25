#include "sudoku.h"

Sudoku::Sudoku(int board[9][9]) {
    for (int row = 0; row < 9; ++row) {
        for (int column = 0; column < 9; ++column) {
            place(board[row][column], column, row);

            for (int value = 0; value <= 9; ++value)
                squares[row/3][column/3][value] = false;
        }
    }

    for (int n = 0; n < 9; ++n) {
        for (int value = 0; value <= 9; ++value) {
            columns[n][value] = false;
            rows[n][value] = false;
        }
    }

}

void Sudoku::place(const int &value, const int &row, const int &column) {
    board[row][column] = value;
    columns[column][value] = true;
    rows[row][value] = true;
    squares[row/3][column/3][value] = true;
    numbers++;
}

void Sudoku::clear(const int &row, const int &column) {
    int value = board[row][column];
    board[row][column] = 0;
    columns[column][value] = false;
    rows[row][value] = false;
    squares[row/3][column/3][value] = false;
    numbers--;
}

bool Sudoku::accepts(const int &value, const int &row, const int &column) const {
    return !columns[column][value] && !rows[row][value] && !squares[row/3][column/3][value];
}

bool Sudoku::complete() const {
    return numbers == 81;
}

bool Sudoku::solve() {
    if (complete()) return true;

    int bestRow, bestColumn, bestP = 10, possibilities;

    for (int row = 0; row < 9; ++row) {
        for (int column = 0; column < 9; ++column) {

            // Ignore already filled squares
            if (board[row][column] != 0) continue;

            // Check Possibilities
            possibilities = 0;
            for (int value = 1; value <= 9; ++value) if (accepts(value, row, column)) possibilities++;  // TODO: Could keep the possibilities in an array for later

            // Check if no possibilities found
            if (possibilities == 0) return false;

            // Compare with Best and change Accordingly
            if (possibilities < bestP) {
                bestRow = row; bestColumn = column;
                bestP = possibilities;
            }
        }
    }

    for (int value = 1; value <= 9; ++value) {
        if (accepts(value, bestRow, bestColumn)) {
            place(value, bestRow, bestColumn);
            if (solve()) return true;
            clear(bestRow, bestColumn);
        }
    }

    return false;
}