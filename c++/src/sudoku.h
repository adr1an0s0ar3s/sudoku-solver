#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku {
private:
    int board[9][9];
    bool columns[9][10];
    bool rows[9][10];
    bool squares[3][3][10];
    int numbers;

    // TODO: Documentation
    void place(const int &value, const int &row, const int &column);
    void clear(const int &row, const int &column);
    bool accepts(const int &value, const int &row, const int &column) const;
    bool complete() const;
public:
    Sudoku(int board[9][9]);
    bool solve();
};

#endif  // SUDOKU_H