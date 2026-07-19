/*
Approach:
1. Sort the array so duplicate candidates come together.
2. Use backtracking to explore all possible combinations.
3. Each element can be used only once, so after picking candidates[i],
   recurse with i + 1.
4. Skip duplicate values at the same recursion level:
      if (i > start && candidates[i] == candidates[i - 1]) continue;
   This avoids duplicate combinations.
5. Since the array is sorted, if candidates[i] > target, break.
*/


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