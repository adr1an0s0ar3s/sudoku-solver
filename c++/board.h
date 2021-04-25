#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
private:
    std::vector<std::vector<int>> board;
    std::vector<std::vector<bool>> columns;
    std::vector<std::vector<bool>> rows;
    std::vector<std::vector<bool>> squares;
public:
    Board(std::vector<std::vector<int>> &board);

    // Auxiliary
    bool checkColumn(const int &value, const int &column) const;
    bool checkRow(const int &value, const int &row) const;
    bool checkSquare(const int &value, const int &column, const int &row) const;
};

#endif  // BOARD_H