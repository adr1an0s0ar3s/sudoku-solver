#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <fstream>
#include <string>

class Sudoku {
private:
    int board[9][9];
    bool columns[9][10];
    bool rows[9][10];
    bool squares[3][3][10];
    int numbers;

    /**
     * @brief Places the value in the respective cell, updates the respective boolean in the arrays and the number count
     * 
     * @param value The value that we want to put in the cell
     * @param row The row of the cell
     * @param column The column of the cell
     */
    void place(const int &value, const int &row, const int &column);

    /**
     * @brief Clears (=0) the value in the respective cell, updates the respective boolean in the arrays and the number count
     * 
     * @param row The row of the cell
     * @param column The column of the cell
     */
    void clear(const int &row, const int &column);

    /**
     * @brief Checks if the value can be inputed in the respective cell and returns a boolean
     * 
     * @param value The value that we want to put in the cell
     * @param row The row of the cell
     * @param column The column of the cell
     * @return True, if the value is valid, False otherwise
     */
    bool accepts(const int &value, const int &row, const int &column) const;

    /**
     * @brief States if all the cells in the Sudoku board are different than 0 (complete)
     * 
     * @return True if it's complete, False otherwise
     */
    bool complete() const;

public:

    /**
     * @brief Copies the board in its argument and updates the arrays and number count accordingly
     * 
     * @param board Matrix 9x9 with blank spaces filled by 0
     */
    Sudoku(int board[9][9]);

    /**
     * @brief Copies the board in the file and updates the arrays and number count accordingly
     * 
     * @param filePath The file that contains the board (each line with "row column value" without blank spaces)
     */
    Sudoku(char *filePath);

    /**
     * @brief Solves the board and returns a boolean stating if it's possible or not
     * 
     * @return True, if it was able to find a solution, False otherwise
     */
    bool solve();

    /**
     * @brief Prints the board
     * 
     * @param out Output stream
     */
    void print(std::ostream &out) const;

    friend std::ostream& operator<<(std::ostream &out, const Sudoku &s);
};

#endif  // SUDOKU_H