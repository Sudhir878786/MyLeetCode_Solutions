class Solution {
public:
    bool func(vector<int>&nums,int i,vector<int>&dp)
    {
        if(i==nums.size()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        // case 1
        if(i+1<nums.size() and nums[i]==nums[i+1]){
            if(func(nums,i+2,dp)){
                return true;
            }
            //case 3
            if(i+2<nums.size() and nums[i]==nums[i+2]){
                if(func(nums,i+3,dp)){
                    return true;
                }
            }
            
        }
        // case 3
        if(i+2<nums.size() and nums[i]==nums[i+1]-1 and nums[i]==nums[i+2]-2){
            if(func(nums,i+3,dp)){
                return true;
            }
        }
        return dp[i]= false;
    }
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return func(nums,0,dp);
    }
};