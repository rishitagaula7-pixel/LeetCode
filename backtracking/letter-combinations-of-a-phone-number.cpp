class Solution {
public:
    vector<string> result;
    
    void backtrack(string &digits, int index, string &current,
                   vector<string> &mapping) {
        // Base case: full combination formed
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }
        
        int digit = digits[index] - '0';
        
        // Try all letters for the current digit
        for (char ch : mapping[digit]) {
            current.push_back(ch);          // choose
            backtrack(digits, index + 1, current, mapping); // explore
            current.pop_back();              // un-choose
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };
        
        string current = "";
        backtrack(digits, 0, current, mapping);
        return result;
    }
};
