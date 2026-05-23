class Solution {
public:
    int divide(int dividend, int divisor) {
        // Overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Use long long to prevent overflow
        long long dvd = llabs((long long) dividend);
        long long dvs = llabs((long long) divisor);
        long long quotient = 0;

        // Main logic using bit shifting
        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;

            while ((temp << 1) <= dvd) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            quotient += multiple;
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0))
            quotient = -quotient;

        return (int) quotient;
    }
};
