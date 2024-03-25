class Solution {
public:
    int myAtoi(string s) {
        double	res;
        int	i;
        int	signe;

        res = 0;
        i = 0;
        signe = 1;
        while (s[i] == '\t' || s[i] == '\n'
            || s[i] == '\v' || s[i] == '\f' || s[i] == '\r'
            || s[i] == ' ')
            i++;
        if (s[i] == '-' || s[i] == '+')
        {
            if (s[i] == '-')
                signe *= -1;
            i++;
        }
        while (s[i] >= '0' && s[i] <= '9')
            res = res * 10 + s[i++] - '0';
        res = signe * res;
         if (res > INT_MAX)
            return INT_MAX;
        if (res < INT_MIN)
            return INT_MIN;
        return (res);
    }
};