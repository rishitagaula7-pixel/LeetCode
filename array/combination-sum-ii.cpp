class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(int idx, int target, vector<int>& candidates) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates at same level
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break; // pruning

            path.push_back(candidates[i]);
            backtrack(i + 1, target - candidates[i], candidates);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates);
        return ans;
    }
};