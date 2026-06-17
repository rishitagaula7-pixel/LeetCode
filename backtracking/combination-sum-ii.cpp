class Solution {
private:
    void findCombinations(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
        // Change 3: Directly check if target is reached
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        // Change 2: Loop to pick next numbers and skip duplicates
        for (int i = ind; i < arr.size(); i++) {
            if (i > ind && arr[i] == arr[i - 1]) continue; 
            if (arr[i] > target) break; 

            ds.push_back(arr[i]);
            findCombinations(i + 1, target - arr[i], arr, ans, ds); // Note: i + 1
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        // Change 1: Sorting is mandatory here
        sort(candidates.begin(), candidates.end()); 
        
        findCombinations(0, target, candidates, ans, ds);
        return ans;
    }
};
