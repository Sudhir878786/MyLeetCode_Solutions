class Solution {
public:
    int func(int i,vector<int>&nums,int k,vector<vector<int>>&dp)
    {
        if(i==0){
            return (k%nums[0]==0);
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int nott=0+func(i-1,nums,k,dp);
        int take=0;
        if(nums[i]<=k)
        {
            take=func(i,nums,k-nums[i],dp);
        }
        return dp[i][k]= take+nott;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return func(n-1,coins,amount,dp);
    }
};