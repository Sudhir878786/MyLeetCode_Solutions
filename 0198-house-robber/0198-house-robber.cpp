class Solution {
public:
    int func(vector<int>&nums,int n,vector<int>&dp)
    {
        if(n<0)return 0;
        if(n==0)return  nums[n];
        if(dp[n]!=-1)return dp[n];
        int pick=nums[n]+func(nums,n-2,dp);
        int notp=0+func(nums,n-1,dp);
        return dp[n]=max(pick,notp);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return func(nums,n-1,dp);
    }
};