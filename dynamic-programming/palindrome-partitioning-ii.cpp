class Solution {
public:
    bool isPallindrome(int i, int j, string &s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i, int n, string &s, vector<int> &dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];

        int minCost = INT_MAX;
        for(int j = i; j < n; j++){
            if (isPallindrome(i, j, s)){
                // FIXED: Now correctly passing all 4 arguments (including dp)
                int cost = 1 + f(j + 1, n, s, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[i] = minCost;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, n, s, dp) - 1;
    }
};

