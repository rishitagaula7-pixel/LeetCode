class Solution {
public:
    
    long long heightRemoved(long long time, int t){
        long long l = 0, r = 2e5;
        
        while(l <= r){
            long long mid = (l + r) / 2;
            long long cost = (long long)t * mid * (mid + 1) / 2;
            
            if(cost <= time) l = mid + 1;
            else r = mid - 1;
        }
        
        return r;
    }
    
    bool can(long long time, int H, vector<int>& w){
        long long total = 0;
        
        for(int t : w){
            total += heightRemoved(time, t);
            if(total >= H) return true;
        }
        
        return total >= H;
    }
    
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long l = 1, r = 1e18;
        long long ans = r;
        
        while(l <= r){
            long long mid = (l + r) / 2;
            
            if(can(mid, mountainHeight, workerTimes)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        
        return ans;
    }
};