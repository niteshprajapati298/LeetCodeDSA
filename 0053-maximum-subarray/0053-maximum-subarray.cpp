class Solution {
public:
    int maxSubArray(vector<int>& nums) {
   
        int maxi = INT_MIN;
        

        // for(int i = 0; i < nums.size(); i++){
        //     int sum = 0;
        //     for(int j = i; j< nums.size(); j++){
        //        sum+= nums[j];
        //        maxi = max(sum,maxi);
        //     }
        // }
        // return maxi;
        int sum = 0;
        for(int i =0 ; i < nums.size(); i++){
            if(sum < 0){
                sum = 0;
            };
            sum+=nums[i];
            maxi = max(sum,maxi);
        }
        return maxi;
    }
};