class Solution {
public:
    int reverse(int x) {
        long rev_x = 0;
        while (x) { 
            rev_x = rev_x * 10 + x % 10; 
            x = x / 10; 
        } 
        if(rev_x > INT_MAX || rev_x < INT_MIN) return 0;
        return rev_x; 
    }
};
