class Solution {
public:
    int func(int n,int am, vector<int>&nums,vector<vector<int>>&dp)
    {
        if(n==0){
            if(am%nums[0]==0)return am/nums[0];
            else return 1e9;
        }
        if(dp[n][am]!=-1)return dp[n][am];
        int nott=func(n-1,am,nums,dp);
        int take=1e9;
        if(am>=nums[n]){
            take=1+func(n,am-nums[n],nums,dp);
        }
        return dp[n][am]=min(take,nott);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans= func(n-1,amount,coins,dp);
        if(ans>=1e9)return -1;
        return ans;
    }
};