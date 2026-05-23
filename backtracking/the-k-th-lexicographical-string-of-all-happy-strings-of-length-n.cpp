class Solution {
public:
    string ans = "";
    
    void solve(int n, int &k, string curr) {
        if(curr.length() == n) {
            k--;
            if(k == 0) ans = curr;
            return;
        }
        
        for(char ch : {'a','b','c'}) {
            if(curr.empty() || curr.back() != ch) {
                solve(n, k, curr + ch);
                if(ans != "") return;
            }
        }
    }
    
    string getHappyString(int n, int k) {
        solve(n, k, "");
        return ans;
    }
};