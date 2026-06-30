class Solution {
public:
    int romanToInt(string s) {
        // Map to store Roman numeral values
        // Using an array or switch is faster than unordered_map in C++
        auto getValue = [](char c) {
            switch(c) {
                case 'I': return 1;
                case 'V': return 5;
                case 'X': return 10;
                case 'L': return 50;
                case 'C': return 100;
                case 'D': return 500;
                case 'M': return 1000;
                default: return 0;
            }
        };
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            int currentVal = getValue(s[i]);
            
            // If current value is less than the next value, subtract it
            if (i + 1 < n && currentVal < getValue(s[i + 1])) {
                total -= currentVal;
            } else {
                total += currentVal;
            }
        }
        
        return total;
    }
};
