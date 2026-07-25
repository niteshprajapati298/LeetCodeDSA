class Solution {
public:
    void solve(vector<int>&nums, vector<int>ds, vector<bool>&visited, int n ,vector<vector<int>>&ans) {
        if (ds.size() == n) {
            ans.push_back(ds);

        }
        for(int i = 0 ; i < nums.size(); i++){
                  if(visited[i]== 0) { visited[i] = 1;
                  ds.push_back(nums[i]);
                  solve(nums, ds,visited, n, ans);
                  visited[i] = 0;
                  ds.pop_back();
                  }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        vector<bool>temp(nums.size(), false);
        int n = nums.size();
        solve(nums, ds,temp, n, ans);
        return ans;
    }
};