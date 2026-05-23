class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, vector<int>& temp, vector<bool>& used) {
        // Base case: one permutation formed
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Try each number
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;   // skip if already used

            // Choose
            used[i] = true;
            temp.push_back(nums[i]);

            // Explore
            backtrack(nums, temp, used);

            // Unchoose (Backtrack)
            temp.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<bool> used(nums.size(), false);

        backtrack(nums, temp, used);
        return ans;
    }
};
