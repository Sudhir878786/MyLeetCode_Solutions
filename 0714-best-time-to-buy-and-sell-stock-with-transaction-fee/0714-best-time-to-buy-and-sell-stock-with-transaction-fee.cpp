class Solution {
public:
    int func(int i,int buy,int n,int fee,vector<int>&prices,vector<vector<int>>&dp)
    {
        if(i==n){
            return 0;
        }
        if(dp[i][buy]!=-1)return dp[i][buy];
        int ans=INT_MIN;
        if(buy==0){
            ans=max(0+func(i+1,0,n,fee,prices,dp),-prices[i]+func(i+1,1,n,fee,prices,dp));
        }
        if(buy==1){
            ans=max(0+func(i+1,1,n,fee,prices,dp),prices[i]-fee+func(i+1,0,n,fee,prices,dp));
        }
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int  n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2+1,-1));
        return func(0,0,n,fee,prices,dp);
    }
};