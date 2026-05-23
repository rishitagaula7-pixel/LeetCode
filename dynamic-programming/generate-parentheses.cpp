class Solution {
public:
    void backtrack(vector<string>& ans, string curr, int open, int close, int n) {
        // If the current string is complete
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Add '(' if we still can
        if (open < n) {
            backtrack(ans, curr + "(", open + 1, close, n);
        }

        // Add ')' only if it keeps the sequence valid
        if (close < open) {
            backtrack(ans, curr + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
};