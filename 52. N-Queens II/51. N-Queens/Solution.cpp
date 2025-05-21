bool checkSafe(vector<vector<string>> &vec, int posx, int posy) {
    int i, j;

    for (i = 0; i < posx; i++) 
        if (vec[i][posy] == "Q")
            return false;

    for (i = posx - 1, j = posy - 1; i >= 0 && j >= 0 ; i--, j--)
        if (vec[i][j] == "Q")
            return false;
        
    for (i = posx - 1, j = posy + 1; j <vec.size() && i >= 0; i--, j++)
        if (vec[i][j] == "Q")
            return false;
    return true;
}

void QueenPlace(int r, vector<string>& board, vector<vector<string>>& res) {
    int n = board.size();
    if (r == n) {
        res.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++) {
        bool safe = true;
        for (int j = 0; j < r; j++) {
            int q_col = board[j].find('Q');
            if (q_col == i || abs(q_col - i) == abs(j - r)) {
                safe = false;
                break;
            }
        }
        if (safe) {
            board[r][i] = 'Q';
            QueenPlace(r + 1, board, res);
            board[r][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> res;
    QueenPlace(0, board, res);
    return res;
}

int totalNQueens(int n) {
    vector<vector<string>> res = solveNQueens(n);
    return res.size();
}
