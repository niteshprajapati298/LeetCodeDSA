class Solution {
public:
    void solve(int index, int target , vector<int>&candidates, vector<vector<int>>&ans, vector<int>ds){
        if(target < 0 ) return;
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i = index ; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i]>target) break;
            target = target - candidates[i];
            ds.push_back(candidates[i]);
            solve(i+1,target,candidates,ans,ds);
            target = target + candidates[i];
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>>ans;
    vector<int>ds;
    int index = 0;
    solve(index , target , candidates,ans,ds);
    return ans;
    }
};