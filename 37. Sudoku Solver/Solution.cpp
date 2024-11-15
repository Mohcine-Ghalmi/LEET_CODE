#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

void solveSudoku(vector<vector<char>>& board) {
        
}

bool hasDuplicates(const std::vector<char>& vec) {
    unordered_set<char> seen;
    for (const auto& str : vec) {
        if (seen.find(str) != seen.end() && str != '.') {
            cout << "repeated = " << str << endl;
            return true;
        }
        seen.insert(str);
    }
    return false;
}

bool check3x3(const std::vector<std::vector<char>>& board, int startRow, int startCol) {
    std::unordered_set<char> seen;
    
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            char val = board[startRow + i][startCol + j];
            if (val != '.' && seen.find(val) != seen.end())
                return true;
            seen.insert(val);
        }
    return false;
}

bool checkForRepeatsInSubgrids(const std::vector<std::vector<char>>& board) {
    for (int i = 0; i < 9; i += 3)
        for (int j = 0; j < 9; j += 3)
            if (check3x3(board, i, j))
                return true;
    return false;
}

bool isValidSudoku(vector<vector<char>>& board) {
    for (auto row : board)
        if (hasDuplicates(row))
            return false;
        vector<char> rowVect;
    for (size_t i = 0; i < board[0].size(); i++) {
        vector<char> newVect;
        for (auto row : board)
            newVect.push_back(row[i]);
        if (hasDuplicates(newVect))
            return false;
    }
    for (int i = 0; i < 9; i += 3)
        for (int j = 0; j < 9; j += 3)
            if (check3x3(board, i, j))
                return false;
    return true;
}
