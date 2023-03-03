class Solution {
public:
    // we can use concept of pic and not pick with dp;
    // we will take a variable buy  if we are not buying (buy==0) then 
    // we can take or not take the cur element 
    // if not buying then ->> we cna move i+1 with current state of buy 
    // if buying then we have loss that curent price and make the i+1 to be 0( to sell)
    int func(int i,int buy,int k,int n,vector<int>&p,vector<vector<vector<int>>>&dp)
    {
        if(k==0||i==n)return 0;
        int prof=0;
        if(dp[i][buy][k]!=-1)return dp[i][buy][k];
        if(buy==0){
            prof=max(0+func(i+1,0,k,n,p,dp),-p[i]+func(i+1,1,k,n,p,dp));
        }
        if(buy==1){
            prof=max(0+func(i+1,1,k,n,p,dp),p[i]+func(i+1,0,k-1,n,p,dp));
        }
        return  dp[i][buy][k]= prof;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(0,0,2,n,prices,dp);
    }
};