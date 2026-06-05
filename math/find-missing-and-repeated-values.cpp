class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& a) {
        long long n = a.size();
        long long N = n * n; // Total elements from 1 to n^2
        
        long long S = 0, S2 = 0;
        
        // Corrected: Nested loops to read every single number
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long val = a[i][j];
                S += val;
                S2 += val * val;
            }
        }
        
        // Corrected formulas using N (total elements)
        long long Sn = (N * (N + 1)) / 2;
        long long S2n = (N * (N + 1) * (2 * N + 1)) / 6;
        
        long long val1 = S - Sn;          // x - y
        long long val2 = S2 - S2n;        // x^2 - y^2
        val2 = val2 / val1;               // x + y
        
        long long x = (val1 + val2) / 2;  // Repeated number
        long long y = x - val1;           // Missing number
        
        return {(int)x, (int)y};
    }
};
