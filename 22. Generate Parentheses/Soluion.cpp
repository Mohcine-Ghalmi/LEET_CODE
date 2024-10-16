void generateParenthesisHelper(int n, int open, int close, string current, vector<string>& result) {
    if (open == n && close == n) {
        result.push_back(current);
        return;
    }

    if (open < n)
        generateParenthesisHelper(n, open + 1, close, current + '(', result);

    if (close < open)
        generateParenthesisHelper(n, open, close + 1, current + ')', result);
}

vector<string> generateParenthesis(int n) {
    vector<string> paraenthesis;
    string cur;
    generateParenthesisHelper(n, 0, 0, cur,paraenthesis);
    return paraenthesis;
}
