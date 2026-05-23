class Solution {
public:
    
    void solve(string s, int index, int parts, string curr, vector<string>& ans) {
        
        if(parts == 4 && index == s.size()) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        
        if(parts >= 4) return;
        
        for(int len = 1; len <= 3 && index + len <= s.size(); len++) {
            
            string part = s.substr(index, len);
            
            if((part[0] == '0' && part.length() > 1) || stoi(part) > 255)
                continue;
            
            solve(s, index + len, parts + 1, curr + part + ".", ans);
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve(s, 0, 0, "", ans);
        return ans;
    }
};