int divide(int dividend, int divisor) {
    if (divisor == 0)
        return 0;

    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    return (round(dividend / divisor));
}
