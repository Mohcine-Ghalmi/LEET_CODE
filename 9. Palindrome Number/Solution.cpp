class Solution {
public:
    bool isPalindrome(int x) {
        long long n, digit, rev = 0;
        n = x;
        if (x < 0) return false;
        do
        {
            digit = x % 10;
            rev = (rev * 10) + digit;
            x = x / 10;
        } while (x != 0);

        if (n == rev)
            return true;
        return false;
    }
};