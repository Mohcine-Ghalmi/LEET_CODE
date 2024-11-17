bool isValidPos(vector<vector<char> > &board, int row, int col, char num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num)
            return false;
        if (board[i][col] == num)
            return false;
        if (board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == num) 
            return false;
    }
    return true;
}

bool sudokuSolve(vector<vector<char> > &board) {
    for (int row = 0; row < 9; row++)
        for (int col = 0; col < 9; col++)
            if (board[row][col] == '.') {
                for (char num = '1' ; num <= '9'; num++) {
                    if (isValidPos(board, row, col, num)) {
                        board[row][col] = num;
                        if (sudokuSolve(board))
                            return true;
                        board[row][col] = '.';
                    }
                }
                return false;
            }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    sudokuSolve(board);
}
