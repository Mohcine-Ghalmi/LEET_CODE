double myPow(double x, int n) {
    double result = 1.0;
    long long N = n;
    if (N < 0) {
        x = 1 / x;
        N = -N;
    }
    while (N > 0) {
        if (N % 2 == 1)
            result *= x;
        x *= x;
        N /= 2;
    }
    return result;
}
