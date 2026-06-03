class Solution {
public:
    int maxProfit(vector<int>& price) {
        int i;
        int mini= price[i];
        int maxprofit=0;
        for(int i=0;i<price.size();i++){
            int cost=price[i]-mini;
            maxprofit= max(maxprofit,cost);
            mini=min(mini,price[i]);
        }
        return maxprofit;
        
    }
};