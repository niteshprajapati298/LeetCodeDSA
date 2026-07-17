class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int prev = -1;
        // int current = -1;
        // for(int i = 1; i < nums.size(); i++){
        //      prev = nums[i-1];
        //      current = nums[i];
        //     if(prev == current) return prev;
        //  }
        //  return -1;
        

       //  -------->>>>>>>>>> with modifying the array;
    //   int i = 0;
    //        while(i<nums.size()){
    //         while(nums[i]!=nums[nums[i]]){
    //             swap(nums[i],nums[nums[i]]);
    //         }
    //          i++;
    //     };
    //    return nums[0];


       unordered_map<int,int>mp;
       for(auto num : nums){
           if(mp.find(num)!=mp.end()){
            return num;
           }
           else mp[num] = 1;
       }
       return -1;
    }
};