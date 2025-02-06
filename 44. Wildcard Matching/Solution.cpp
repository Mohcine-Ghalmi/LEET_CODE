#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool wildCardRec(string& txt, string& pat, int n, int m) {
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;

    for (int j = 1; j <= m; j++) {
        if (pat[j - 1] == '*')
            dp[0][j] = dp[0][j - 1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (pat[j - 1] == '*')
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            else if (pat[j - 1] == '?' || txt[i - 1] == pat[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
        }
    }

    return dp[n][m];
}

bool isMatch(string s, string p) {
    int n = s.size();
    int m = p.size();
    return wildCardRec(s, p, n, m);
}

int main(void) {

    cout << isMatch("aaa", "*") << endl;


    return (0);
}