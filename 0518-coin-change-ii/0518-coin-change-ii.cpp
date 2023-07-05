class Solution {
public:
    int func(int i,vector<int>&coins,int amount,vector<vector<int>>&dp)
    {
        if(i==0){
            return  (amount%coins[0]==0);
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int nott=0+func(i-1,coins,amount,dp);
        int take=0;
        if(coins[i]<=amount){
            take=func(i,coins,amount-coins[i],dp);
        }
        return dp[i][amount] = take+nott;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return func(n-1,coins,amount,dp);
        
    }
};