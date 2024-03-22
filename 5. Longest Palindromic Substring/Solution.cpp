class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLength = 1, start = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        
        for (int i = 0; i < n - 1; i++)
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        
        for (int len = 3; len <= n; len++)
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    start = i;
                    maxLength = len;
                }
            }
        
        return s.substr(start, maxLength);
    }
};