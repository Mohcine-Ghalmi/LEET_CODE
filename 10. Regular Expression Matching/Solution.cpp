class Solution {
public:
    bool isMatch(string s, string p) {
        regex regexPattern(p);
        return regex_match(s, regexPattern);
    }
};