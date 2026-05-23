class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void backtrack(vector<int>& candidates, int target, int start) {
        // Base case: exact sum achieved
        if (target == 0) {
            result.push_back(path);
            return;
        }

        // Try all candidates starting from 'start'
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target)
                continue;

            path.push_back(candidates[i]);
            // i (not i+1) because we can reuse same element
            backtrack(candidates, target - candidates[i], i);
            path.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0);
        return result;
    }
};