class Solution {
public:
     void solve(int index, int target, vector<int>& candidates,
               vector<vector<int>>& ans, vector<int>& ds) {
        
        if (target < 0)
            return;

        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        if (index == candidates.size())
            return;

        // Pick
        ds.push_back(candidates[index]);
        target = target - candidates[index];
        solve(index, target, candidates, ans, ds);

        // Backtrack
        ds.pop_back();
        target = target + candidates[index];

        // Not Pick
        solve(index + 1, target, candidates, ans, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int index = 0;
        solve(index, target, candidates, ans, ds);
        return ans;
    }
};