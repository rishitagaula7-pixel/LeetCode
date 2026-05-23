class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s + s;   // simulate rotations
        
        string alt1 = "", alt2 = "";
        
        // create alternating patterns
        for(int i = 0; i < 2*n; i++){
            if(i % 2 == 0){
                alt1 += '0';
                alt2 += '1';
            }
            else{
                alt1 += '1';
                alt2 += '0';
            }
        }
        
        int diff1 = 0, diff2 = 0;
        int l = 0;
        int ans = INT_MAX;
        
        for(int r = 0; r < 2*n; r++){
            
            if(ss[r] != alt1[r]) diff1++;
            if(ss[r] != alt2[r]) diff2++;
            
            if(r - l + 1 > n){
                if(ss[l] != alt1[l]) diff1--;
                if(ss[l] != alt2[l]) diff2--;
                l++;
            }
            
            if(r - l + 1 == n){
                ans = min(ans, min(diff1, diff2));
            }
        }
        
        return ans;
    }
};