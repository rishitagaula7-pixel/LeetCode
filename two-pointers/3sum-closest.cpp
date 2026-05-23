#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];
                
                // Update closest sum
                if (abs(currSum - target) < abs(closestSum - target)) {
                    closestSum = currSum;
                }
                
                if (currSum < target) {
                    left++;
                } else if (currSum > target) {
                    right--;
                } else {
                    // Exact match found
                    return currSum;
                }
            }
        }
        
        return closestSum;
    }
};
