class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // with Brute Force approach
        int n = nums.size()-1;
        unordered_map<int,int>mp;
        for(int i = 0; i <= n; i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            if(it.second > n/2) return it.first;
          }
          return 0;
    }
};