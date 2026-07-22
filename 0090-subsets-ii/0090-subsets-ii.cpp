class Solution {
public:
    void solve(vector<int>&nums,int index , vector<int>&ds, vector<vector<int>>&ans){
        ans.push_back(ds);
       
     for(int i = index ; i < nums.size(); i++){
        if(i > index  && nums[i] == nums[i-1]) continue;
        ds.push_back(nums[i]);
        solve(nums,i+1, ds, ans);
        ds.pop_back();
     }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>ds;
        int index = 0;
        solve(nums,index,ds,ans);
        return ans;
    }
};