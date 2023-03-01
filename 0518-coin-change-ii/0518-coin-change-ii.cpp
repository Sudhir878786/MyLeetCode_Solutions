class Solution {
public:
    int func(int n,  int sum,vector<int>&nums, vector<vector<int>>&dp)
    {
        if(n==0)
        {
        return (sum%nums[0]==0);
            // else return -1;
            
        }
        if(dp[n][sum]!=-1)return dp[n][sum];
        int nott=0+func(n-1,sum,nums,dp);
        int take=0;
        // cout<<nott<<endl;
        // cout<<"take--"<<endl;
        if(sum>=nums[n]){
            take=func(n,sum-nums[n],nums,dp);
            // cout<<take<<endl;
        }
        return dp[n][sum]=take+nott;
    }
    int change(int sum, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return func(n-1,sum,coins,dp);
    }
};